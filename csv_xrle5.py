#!/usr/bin/env python3
from pathlib import Path
import sys, math, csv
import numpy as np

DEFAULT_NAME = "data.csv"   # your file name

def find_header_index(path: Path) -> int:
    with path.open("r", encoding="utf-8", errors="ignore") as f:
        for i, line in enumerate(f):
            if line.strip().lower().startswith("alpha"):
                return i
    raise ValueError("Could not find header line starting with 'alpha'.")

def parse_polar(path: Path):
    hdr_idx = find_header_index(path)
    alphas, cls, cds, cms = [], [], [], []
    with path.open("r", encoding="utf-8", errors="ignore") as f:
        lines = f.readlines()
    reader = csv.DictReader(lines[hdr_idx:], skipinitialspace=True)
    def norm(k): return k.lower().strip().replace(" ", "")
    keys = {norm(k): k for k in (reader.fieldnames or [])}
    need = {}
    for want in ("alpha", "cl", "cd", "cm"):
        if want in keys:
            need[want] = keys[want]
        else:
            found = None
            for k in keys:
                if k.startswith(want):
                    found = keys[k]; break
            if not found:
                raise KeyError(f"Missing column '{want}'. Found: {reader.fieldnames}")
            need[want] = found
    for row in reader:
        try:
            a  = float(str(row[need["alpha"]]).strip())
            cl = float(str(row[need["cl"]]).strip())
            cd = float(str(row[need["cd"]]).strip())
            cm = float(str(row[need["cm"]]).strip())
        except (TypeError, ValueError):
            continue
        alphas.append(a); cls.append(cl); cds.append(cd); cms.append(cm)
    return np.array(alphas), np.array(cls), np.array(cds), np.array(cms)

def clean_physical(alpha, Cl, Cd, Cm):
    ok = np.isfinite(alpha) & np.isfinite(Cl) & np.isfinite(Cd) & np.isfinite(Cm)
    ok &= (Cd > 0.0) & (Cd < 1.0)
    ok &= (np.abs(Cl) < 5.0)
    ok &= (alpha > -30.0) & (alpha < 30.0)
    return alpha[ok], Cl[ok], Cd[ok], Cm[ok]

def linfit(x, y):
    X = np.vstack([x, np.ones_like(x)]).T
    m, b = np.linalg.lstsq(X, y, rcond=None)[0]
    return m, b

def main():
    csv_path = Path(sys.argv[1]).expanduser().resolve() if len(sys.argv) >= 2 else (Path(__file__).parent / DEFAULT_NAME).resolve()
    print(f"Reading: {csv_path}")
    if not csv_path.exists():
        print("ERROR: file not found."); sys.exit(1)

    alpha, Cl, Cd, Cm = parse_polar(csv_path)

    print("\nHEAD (raw parsed)")
    for i in range(min(8, len(alpha))):
        print(f"{alpha[i]:6.1f}  Cl={Cl[i]:7.3f}  Cd={Cd[i]:7.4f}  Cm={Cm[i]:7.3f}")

    alpha, Cl, Cd, Cm = clean_physical(alpha, Cl, Cd, Cm)

    if alpha.size == 0:
        print("\nERROR: No valid rows after cleaning.\nCheck: header line, delimiter, columns (alpha/CL/Cd/Cm), and that Cd isn’t all <= 0.")
        sys.exit(2)

    idx = np.argsort(alpha)
    alpha, Cl, Cd, Cm = alpha[idx], Cl[idx], Cd[idx], Cm[idx]

    print("\nRanges (after cleaning)")
    print(f"alpha: {alpha.min():.1f} → {alpha.max():.1f}")
    print(f"Cl   : {Cl.min():.3f} → {Cl.max():.3f}")
    print(f"Cd   : {Cd.min():.4f} → {Cd.max():.4f}")
    print(f"Cm   : {Cm.min():.3f} → {Cm.max():.3f}") 

    # Metrics
    i_clmax = int(np.argmax(Cl)); CLmax = Cl[i_clmax]; a_stall = alpha[i_clmax]
    CDmin = float(np.min(Cd))
    LD = Cl / Cd; i_ldmax = int(np.argmax(LD)); LDmax = LD[i_ldmax]; a_ldmax = alpha[i_ldmax]; CL_LDmax = Cl[i_ldmax]

    mask = (alpha >= -4.0) & (alpha <= 8.0)
    if mask.sum() < 2:
        lo = len(alpha)//6; hi = len(alpha)-lo
        mask = np.zeros_like(alpha, dtype=bool); mask[lo:hi] = True
    m_deg, b = linfit(alpha[mask], Cl[mask])
    CLalpha_per_deg = m_deg
    CLalpha_per_rad = m_deg * (180.0 / math.pi)
    alpha_L0 = -b / m_deg

    X = np.vstack([np.ones_like(Cl), Cl**2]).T
    CD0, k = np.linalg.lstsq(X, Cd, rcond=None)[0]

    print("\nRESULTS")
    print(f"CLmax ≈ {CLmax:.3f} @ α ≈ {a_stall:.1f}°")
    print(f"CDmin ≈ {CDmin:.4f}")
    print(f"(L/D)max ≈ {LDmax:.1f} @ α ≈ {a_ldmax:.1f}° (CL ≈ {CL_LDmax:.2f})")
    print(f"CLα ≈ {CLalpha_per_rad:.2f} per rad  (≈ {CLalpha_per_deg:.3f} per deg),  α_L=0 ≈ {alpha_L0:.1f}°")
    print(f"Drag polar: Cd ≈ {CD0:.4f} + {k:.4f} · Cl²")

    print("\nExpected bands (NACA 4412 @ Re~2e5):")
    print("  CLmax ~ 1.3–1.5, αstall ~ 11–13°, CDmin ~ 0.010–0.016,")
    print("  CLα ~ 0.09–0.11 per deg (≈ 5–6 per rad), (L/D)max ~ 50–80 (2D)")

if __name__ == "__main__":
    main()
