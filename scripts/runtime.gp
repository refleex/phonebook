reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.100]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using 3:xtic(1) with histogram title 'optimized'  , \
'' using 4:xtic(1) with histogram title 'hash'  , \
'' using ($0+0.4):(0.08): 2 with labels title ' ' textcolor lt 1, \
'' using ($0+0.4):(0.076):3 with labels title ' ' textcolor lt 2, \
'' using ($0+0.4):(0.072):4 with labels title ' ' textcolor lt 3
