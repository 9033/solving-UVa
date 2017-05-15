import sys

for line in sys.stdin:
    N, A = map(int,line.split()) #get two integers in a line
    S = 0;
    Apowi = 1
    for i in range(1,N+1):
        Apowi = Apowi * A
        S = S + i * (Apowi)
    print(S)
