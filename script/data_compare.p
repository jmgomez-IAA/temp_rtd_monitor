#/usr/bin/gnuplot
#
# PLOTs the temperature of Lakeshore vs ADS1248
#
# Author jmgomez

reset

#Output png
# Set the output to a png file 
set terminal png size 1280,720
set output 'res/lk_vs_ads1248_wfilter.png'

# Line styles
set border linewidth 1.5
set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2  # blue
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 2  # red

# Legend
set key at 6.1,1.3
# Axes label 
set xlabel 'Seconds'
set ylabel 'Degree C'

# first draw the minor tics
#set xrange [0:2000]
#set mxtics 10
#set yrange [20:40]
#set mytics 5
#set grid mxtics mytics ls 101

set grid

# Data Files
plot 'data/lk_fil_3-17-21_normalizado.dat' using 6:4 with lines title "ADS1248", 'data/ads1248_fil_3-17-21_normalizado.dat' using 6:4 with lines title "Lakeshore"
