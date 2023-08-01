2. Time analysis of different sorting methods

Sort a given set of elements using the Quicksort and bubble sort method and
determine the time required to sort the elements. Repeat the experiment for different
values of n, the number of elements in the list to be sorted and plot a graph of the time
taken versus n. The elements can be generated using the random number generator.

GNU plot commands used :

```shell
gnuplot> plot "sort.dat" using 1:2 title 'Bubble' with linespoints smooth bezier, "sort.dat" using 1:3 title 'Quick' with linespoints smooth bezier

gnuplot> set logscale

gnuplot> set title "Bubble Sort Vs Quick Sort"

gnuplot> set xlabel "Size(n) -->"

gnuplot> set ylabel "log[Time(s)] -->"

gnuplot> replot

```