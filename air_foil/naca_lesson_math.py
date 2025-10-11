import numpy as np

# === Input targets ===
CL_target = 1.0        # Required lift coefficient at zero angle
Cm_target = -0.25      # Required moment coefficient about quarter chord
t_c = 0.10             # Thickness ratio (10% thickness)

# === Step 1. define relations from thin-airfoil theory ===
def CL0_from_geom(m, p):
    # zero-lift angle relation (radians)
    alpha_L0 = (m / (p**2)) * (2 - p)
    # convert to CL0
    return -2 * np.pi * alpha_L0

def Cm_from_geom(m, p):
    # quarter-chord moment (thin-airfoil theory)
    return -0.5 * np.pi * m * (1 - 2 * p)

# === Step 2. search p & m values ===
best_err = 1e9
best_m, best_p = None, None

p_values = np.linspace(0.1, 0.6, 51)   # from 0.1c to 0.6c
for p in p_values:
    # from CL0 eqn -> m expression
    m = (CL_target / (2*np.pi)) * (p**2) / (2 - p)
    Cm = Cm_from_geom(m, p)
    err = abs((Cm - Cm_target) / Cm_target)  # relative error
    if err < best_err:
        best_err = err
        best_m, best_p = m, p

# === Step 3. print results ===
print("=== Designed NACA 4-digit section ===")
print(f"Target CL0 = {CL_target:.2f}, Target Cm = {Cm_target:.2f}")
print(f"Thickness ratio = {t_c*100:.0f}%")
print(f"--> Found camber m = {best_m*100:.1f}%")
print(f"--> Found camber position p = {best_p:.2f} (→ {best_p*100:.0f}% chord)")
print(f"Predicted Cm = {Cm_from_geom(best_m, best_p):.3f}")
print(f"Predicted CL0 = {CL0_from_geom(best_m, best_p):.3f}")
print(f"Estimated NACA code: {int(best_m*100+0.5)}{int(best_p*10+0.5)}{int(t_c*100+0.5)}")
