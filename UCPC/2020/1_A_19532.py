# Baekjoon 19532
# Bruteforce, Math 

import sys

MIN = -999
MAX = 999

a,b,c,d,e,f = map(int, sys.stdin.readline().split())

for x in range(MIN,MAX + 1):
    for y in range(MIN, MAX + 1):
        if a*x + b*y == c and d*x + e*y == f:
            print(x,y)
            break
