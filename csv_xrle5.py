#!/usr/bin/env python3
from pathlib import Path
import sys
import numpy as np
import pandas as pd

DEFAULT_NAME = "data.csv"   # your file name

def read_xflr5_csv(csv_path: Path) -> pd.DataFrame:
    """Read an XFLR5 polar export:
       - Skip preamble until a line starting with 'alpha'
       - Force comma delimiter
       - Return numeric DataFrame with columns: alpha, Cl, Cd, Cm
    """
    p = csv_path.expanduser().resolve()
    if not p.exists():
        raise FileNotFoundError(f"CSV not found: {p}")

    # Find header line (starts with 'alpha')
    with p.open("r", encoding="utf-8", errors="ignore") as f:
        lines = f.readlines()
    hdr_idx = None
    for i, line in enumerate(lines):
        if line.strip().lower().startswith("alpha"):
            hdr_idx = i
            break
    if hdr_idx is None:
        raise ValueError("Could not find a header line starting with 'alpha'.")

    # Read from the header line
    df = pd.read_csv(p, skiprows=hdr_idx, header=0, sep=",", engine="python")
    df.columns = [c.strip() for c in df.columns]

    # Map common column names
    lower = {c.lower(): c for c in df.columns}
    def need(name): 
        if name in lower: return lower[name]
        raise KeyError(f"Missing column '{name}'. Found: {list(df.columns)}")

    a  = need("alpha")
    cl = need("cl")
    cd = need("cd")
    cm = need("cm")

    df = df[[a, cl, cd, cm]].rename(columns={a:"alpha", cl:"Cl", cd:"Cd", cm:"Cm"})
    df = df.apply(pd.to_numeric, errors="coerce").dropna().sort_values("alpha").reset_index(drop=True)
    return df

def main():
    # pick file: arg or DEFAULT_NAME next to this script
    if len(sys.argv) >= 2:
        csv_path = Path(sys.argv[1])
    else:
        csv_path = Path(__file__).parent / DEFAULT_NAME

    print(f"Reading: {csv_path.resolve()}")
    df = read_xflr5_csv(csv_path)

    # --- quick sanity print ---
    print("\nHEAD (parsed)")
    print(df.head(8).to_string(index=False))
    print("\nRanges")
    print("alpha:", df["alpha"].min(), "→", df["alpha"].max())
    print("Cl   :", df["Cl"].min(),    "→", df["Cl"].max())
    print("Cd   :", df["Cd"].min(),    "→", df["Cd"].max())
    print("Cm   :", df["Cm"].min(),    "→", df["Cm"].max())

    # --- core metrics ---
    i_clmax = df["Cl"].idxmax()
    CLmax   = df.loc[i_clmax, "Cl"]
    a_stall = df.loc[i_clmax, "alpha"]

    CDmin = df["Cd"].min()

    df["LD"] = df["Cl"] / df["Cd"]
    i_ldmax  = df["LD"].idxmax()
    LDmax    = df.loc[i_ldmax, "LD"]
    a_ldmax  = df.loc[i_ldmax, "alpha"]
    CL_LDmax = df.loc[i_ldmax, "Cl"]

    # Lift-curve slope (deg-based fit → convert to per rad correctly)
    mask = (df["alpha"] >= -4) & (df["alpha"] <= 8)
    if mask.sum() < 2:
        mask = slice(None)  # fallback
    m_deg, b = np.polyfit(df.loc[mask, "alpha"], df.loc[mask, "Cl"], 1)  # Cl = m*alpha(deg) + b
    CLalpha_per_deg = m_deg
    CLalpha_per_rad = m_deg * (180.0 / np.pi)  # <-- correct conversion
    alpha_L0 = -b / m_deg  # zero-lift AoA (deg)

    # Drag polar: Cd = CD0 + k * Cl^2
    X = np.vstack([np.ones(len(df)), df["Cl"]**2]).T
    CD0, k = np.linalg.lstsq(X, df["Cd"].values, rcond=None)[0]

    print("\nRESULTS")
    print(f"CLmax ≈ {CLmax:.3f} @ α ≈ {a_stall:.1f}°")
    print(f"CDmin ≈ {CDmin:.4f}")
    print(f"(L/D)max ≈ {LDmax:.1f} @ α ≈ {a_ldmax:.1f}° (CL ≈ {CL_LDmax:.2f})")
    print(f"CLα ≈ {CLalpha_per_rad:.2f} per rad  (≈ {CLalpha_per_deg:.3f} per deg),  α_L=0 ≈ {alpha_L0:.1f}°")
    print(f"Drag polar: Cd ≈ {CD0:.4f} + {k:.4f} · Cl²")

if __name__ == "__main__":
    main()
