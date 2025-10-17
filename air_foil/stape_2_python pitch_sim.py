
# pitch_sim_headless.py
import os, numpy as np, matplotlib, matplotlib.pyplot as plt, pandas as pd
matplotlib.use('Agg')

rho, U0, S, cbar, m, Iy = 1.225, 16.0, 0.22, 0.166, 2.0, 0.08
CZa, CZq, CZde, Cma, Cmq, Cmde = -5.5, -0.0415, -0.6, -1.0, -0.06225, -1.1
delta_e_step_deg, t_step = -5.0, 0.2
t0, tf, dt = 0.0, 8.0, 0.002

qbar = 0.5 * rho * U0**2
Z_a, Z_q, Z_de = qbar*S*CZa, qbar*S*CZq, qbar*S*CZde
M_a, M_q, M_de = qbar*S*cbar*Cma, qbar*S*cbar*Cmq, qbar*S*cbar*Cmde

A = np.array([[ Z_a/(m*U0), Z_q/(m*U0) + 1.0, 0.0],[ M_a/Iy, M_q/Iy, 0.0],[ 0.0, 1.0, 0.0]])
B = np.array([[ Z_de/(m*U0) ],[ M_de/Iy ],[ 0.0 ]])

delta_e_step = np.deg2rad(delta_e_step_deg)
def delta_e(t): return delta_e_step if t >= t_step else 0.0

t = np.arange(t0, tf + dt, dt); N = len(t); x = np.zeros((3, N))
def f(xvec, tcur):
    u = np.array([[delta_e(tcur)]]); 
    return (A @ xvec.reshape(-1,1) + B @ u).flatten()

for k in range(N - 1):
    xk, tk = x[:, k], t[k]
    k1 = f(xk, tk); k2 = f(xk + 0.5*dt*k1, tk + 0.5*dt)
    k3 = f(xk + 0.5*dt*k2, tk + 0.5*dt); k4 = f(xk + dt*k3, tk + dt)
    x[:, k+1] = xk + (dt/6.0)*(k1 + 2*k2 + 2*k3 + k4)

alpha, q, theta = x[0,:], x[1,:], x[2,:]
out_dir = 'air_foil/stage2_data_analysis'; os.makedirs(out_dir, exist_ok=True)
csv_path = os.path.join(out_dir, 'pitch_simulation_timeseries.csv')
pd.DataFrame({'t_s': t, 'alpha_deg': np.rad2deg(alpha), 'q_deg_s': np.rad2deg(q), 'theta_deg': np.rad2deg(theta), 'delta_e_deg': [0.0 if ti < t_step else delta_e_step_deg for ti in t]}).to_csv(csv_path, index=False)

plt.figure(figsize=(8,4.5)); plt.plot(t, np.rad2deg(alpha)); plt.axvline(t_step, linestyle='--'); plt.xlabel('Time [s]'); plt.ylabel('α [deg]'); plt.title('Elevator step response — α(t)'); plt.grid(True); plt.tight_layout(); plt.savefig(os.path.join(out_dir, 'alpha_response.png'), dpi=150); plt.close()
plt.figure(figsize=(8,4.5)); plt.plot(t, np.rad2deg(theta)); plt.axvline(t_step, linestyle='--'); plt.xlabel('Time [s]'); plt.ylabel('θ [deg]'); plt.title('Elevator step response — θ(t)'); plt.grid(True); plt.tight_layout(); plt.savefig(os.path.join(out_dir, 'theta_response.png'), dpi=150); plt.close()
plt.figure(figsize=(8,4.5)); plt.plot(t, np.rad2deg(q)); plt.axvline(t_step, linestyle='--'); plt.xlabel('Time [s]'); plt.ylabel('q [deg/s]'); plt.title('Elevator step response — q(t)'); plt.grid(True); plt.tight_layout(); plt.savefig(os.path.join(out_dir, 'q_response.png'), dpi=150); plt.close()

print('Saved:', csv_path)