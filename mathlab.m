pkg load symbolic        % load symbolic toolbox
clear all

% --- Define symbolic variables ---
syms phi theta psi g m real

% --- Rotation matrices (right-handed, aerospace convention) ---
Lpsi = [ cos(psi)  sin(psi)  0;
        -sin(psi)  cos(psi)  0;
         0         0         1];

Ltheta = [ cos(theta)  0  -sin(theta);
            0          1   0;
            sin(theta) 0   cos(theta)];

Lphi = [ 1  0          0;
         0  cos(phi)   sin(phi);
         0 -sin(phi)   cos(phi)];

% --- Combined rotation (Earth to Body) ---
L_BE = simplify(Lphi * Ltheta * Lpsi)

% --- Weight vector in Earth frame ---
W_E = [0; 0; m*g];

% --- Convert to Body frame ---
W_B = simplify(L_BE * W_E)

pretty(W_B)

