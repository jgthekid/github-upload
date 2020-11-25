for x in {1..1000}; do c99 test.sort.c; cat rand.txt |./a.out >> rez1 ; done
