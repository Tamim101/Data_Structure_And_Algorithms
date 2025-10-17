# pitch_sim.py
# Small-angle 2D pitch simulation (Etkin-style)
# States: x = [alpha, q, theta]; Input: elevator deflection delta_e (rad)
# Dynamics:
#   dot(alpha) = (Z_a/(m*U0)) * alpha + (Z_q/(m*U0) + 1.0) * q + (Z_de/(m*U0)) * delta_e
#   dot(q)     = (M_a/Iy) * alpha + (M_q/Iy) * q + (M_de/Iy) * delta_e
#   dot(theta) = q
#
# Edit the "USER INPUT" section with your own aircraft data or pipe them in from a file.

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# -----------------------
# USER INPUT (edit these)
# -----------------------
rho   = 1.225      # air density [kg/m^3] (sea level)
U0    = 16.0       # trim speed [m/s]
S     = 0.22       # wing area [m^2]
cbar  = 0.166      # mean aerodynamic chord [m]
m     = 2.0        # mass [kg]
Iy    = 0.08       # pitch MOI about CG [kg·m^2]

# Nondimensional aero derivatives (starter values; replace with your data)
# Signs: Cz positive DOWN. For a typical wing, CZa ≈ -CL_alpha (per rad).
CZa   = -5.5                           # ∂Cz/∂alpha  [1/rad]
CZq   = -8.0 * (cbar/(2.0*U0))         # ∂Cz/∂(q)     [1/s]
CZde  = -0.6                           # ∂Cz/∂(delta_e) [1/rad]
Cma   = -1.0                           # ∂Cm/∂alpha   [1/rad] (static stability < 0)
Cmq   = -12.0 * (cbar/(2.0*U0))        # ∂Cm/∂(q)     [1/s]
Cmde  = -1.1                           # ∂Cm/∂(delta_e) [1/rad]

# Elevator input (deg). Negative here = pull (nose-up) in this sign convention.
delta_e_step_deg = -5.0
t_step = 0.2       # [s] time when the step is applied

# Simulation horizon
t0, tf, dt = 0.0, 8.0, 0.002

# -----------------------
# Build model
# -----------------------
qbar = 0.5 * rho * U0**2  # dynamic pressure [Pa]

# Convert to dimensional derivatives
Z_a  = qbar * S * CZa                      # [N/rad]
Z_q  = qbar * S * CZq                      # [N/(rad/s)]
Z_de = qbar * S * CZde                     # [N/rad]

M_a  = qbar * S * cbar * Cma               # [N·m/rad]
M_q  = qbar * S * cbar * Cmq               # [N·m/(rad/s)]
M_de = qbar * S * cbar * Cmde              # [N·m/rad]

# State matrices
A = np.array([
    [ Z_a/(m*U0),         Z_q/(m*U0) + 1.0, 0.0],
    [ M_a/Iy,             M_q/Iy,           0.0],
    [ 0.0,                1.0,              0.0]
])
B = np.array([
    [ Z_de/(m*U0) ],
    [ M_de/Iy     ],
    [ 0.0         ]
])

# -----------------------
# Input function
# -----------------------
delta_e_step = np.deg2rad(delta_e_step_deg)
def delta_e(t):
    return delta_e_step if t >= t_step else 0.0

# -----------------------
# Integrate (RK4)
# -----------------------
t = np.arange(t0, tf + dt, dt)
N = len(t)
x = np.zeros((3, N))  # alpha, q, theta

def f(xvec, tcur):
    u = np.array([[delta_e(tcur)]])
    return (A @ xvec.reshape(-1,1) + B @ u).flatten()

for k in range(N - 1):
    xk, tk = x[:, k], t[k]
    k1 = f(xk, tk)
    k2 = f(xk + 0.5*dt*k1, tk + 0.5*dt)
    k3 = f(xk + 0.5*dt*k2, tk + 0.5*dt)
    k4 = f(xk + dt*k3,     tk + dt)
    x[:, k+1] = xk + (dt/6.0)*(k1 + 2*k2 + 2*k3 + k4)

alpha = x[0, :]
q     = x[1, :]
theta = x[2, :]

# -----------------------
# Save and plot
# -----------------------
df = pd.DataFrame({
    "t_s": t,
    "alpha_deg": np.rad2deg(alpha),
    "q_deg_s": np.rad2deg(q),
    "theta_deg": np.rad2deg(theta),
    "delta_e_deg": [0.0 if ti < t_step else delta_e_step_deg for ti in t]
})
df.to_csv("air_foil/pitch_simulation_timeseries.csv", index=False)
print("Saved: air_foil/pitch_simulation_timeseries.csv")

# One figure per variable
plt.figure(figsize=(8,4.5))
plt.plot(t, np.rad2deg(alpha))
plt.axvline(t_step, linestyle="--")
plt.xlabel("Time [s]"); plt.ylabel("α [deg]"); plt.title("Elevator step response — α(t)")
plt.grid(True); plt.tight_layout(); plt.show()

plt.figure(figsize=(8,4.5))
plt.plot(t, np.rad2deg(theta))
plt.axvline(t_step, linestyle="--")
plt.xlabel("Time [s]"); plt.ylabel("θ [deg]"); plt.title("Elevator step response — θ(t)")
plt.grid(True); plt.tight_layout(); plt.show()

plt.figure(figsize=(8,4.5))
plt.plot(t, np.rad2deg(q))
plt.axvline(t_step, linestyle="--")
plt.xlabel("Time [s]"); plt.ylabel("q [deg/s]"); plt.title("Elevator step response — q(t)")
plt.grid(True); plt.tight_layout(); plt.show()
