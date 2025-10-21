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

>> syms m
>> syms u v w p q r u_dot v_dot w_dot
>> m*{[u_dot;v_dot;w_dot]+ cross([p;q;r],[u;v;w])}error: not enough/too much in B
error: called from
    mat_rclist_asgn at line 55 column 5
    mat_replace at line 155 column 5
    subsasgn at line 102 column 13
    cell2sym at line 60 column 15
    sym at line 294 column 7
    mtimes at line 54 column 5



%math
>> m*([u_dot;v_dot;w_dot]+ cross([p;q;r],[u;v;w]))
ans = (sym 3×1 matrix)

  ⎡m⋅(q⋅w - r⋅v + u_dot) ⎤
  ⎢                      ⎥
  ⎢m⋅(-p⋅w + r⋅u + v_dot)⎥
  ⎢                      ⎥
  ⎣m⋅(p⋅v - q⋅u + w_dot) ⎦

>> syms u v w p q r u_dot v_dot w_dot
>> syms m
>> m*([u_dot;v_dot;w_dot]+ cross([p;q;r],[u;v;w]))
ans = (sym 3×1 matrix)

  ⎡m⋅(q⋅w - r⋅v + u_dot) ⎤
  ⎢                      ⎥
  ⎢m⋅(-p⋅w + r⋅u + v_dot)⎥
  ⎢                      ⎥
  ⎣m⋅(p⋅v - q⋅u + w_dot) ⎦

>>
