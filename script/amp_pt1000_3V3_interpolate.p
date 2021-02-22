# Set the output to a png file
set terminal png size 1280,720

# Output file name
set output 'res/amp_pt1000_3V3_interpolate.png'

# Title
set title 'amp_pt1000_3V3 f(v) linear interpolation'

f(x) = m * x + q
fit f(x) 'data/datos_sim_pt1000_oamp_3V3.dat' using 2:0 via m, q

set xrange [0:3]

#plot the graphic
plot 'data/datos_sim_pt1000_oamp_3V3.dat' using 2:0 ls 1 t 'Simulation data', f(x) ls 2 t 'Linear regression'
