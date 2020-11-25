# testing exercise 3.1 time against binsearch
# appropriate edits made in ex3.1.c directly

echo "testing version 1"
time $(for i in {1..10}; do c99 ex3.1.test1.c; ./a.out; done)
echo "testing version 1"
time $(for i in {1..10}; do c99 ex3.1.test2.c; ./a.out; done)
echo "testing version KR"
time $(for i in {1..10}; do c99 ex3.1.testKR.c; ./a.out; done)
