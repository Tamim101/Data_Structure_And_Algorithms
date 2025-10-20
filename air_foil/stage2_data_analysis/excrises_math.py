from pathlib import Path
import sys, math, csv
import numpy as np

#dinamic weight geometric data
wright = 924,488
z_by_c = 0.15
#aerodynamic data 
a_w = 0.080
c_macw = 0.05
c_dmin = 0.013
k = 0.054
v = 180
row_p = 1.225
# get dinamic passure 
velocity_v = v*v
calculate_passure = 0.5*row_p*velocity_v
print("Total passure = ",calculate_passure)

# wing drag polar percentage difference
total_parsentage = math.sqrt((c_macw - c_dmin) / c_dmin)* 100
print(f"Total parsentage is = {total_parsentage:.2f}% ")



