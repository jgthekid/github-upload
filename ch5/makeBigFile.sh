for x in {1..3000}; do head /dev/urandom | LC_ALL=C tr -dc A-Za-z0-9| head -c 13 >> rand.txt; echo '' >> rand.txt ; done
