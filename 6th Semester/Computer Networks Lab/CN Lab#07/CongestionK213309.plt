set terminal png
set output "congestionK213309.png"
set title "Congestion Kindow Calculation K213309"
set xlabel "Time (in seconds)"
set ylabel "Cengestion Window (cwnd)"
plot "seventh.cwnd" using 1:2 with linespoints title "Old Congestion", "seventh.cwnd" using 1:3 with linespoints title "New Congestion"
