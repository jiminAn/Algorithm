import sys
input = sys.stdin.readline

a, d, k = map(int,input().split())

d /= 100
k /= 100

ans, prev, i = 0, 1, 1

while True:
    ans += i * a * prev * d
    i += 1
    
    if d == 1: break
    
    prev *= (1-d)
    d += d * k

    if d >= 1: d = 1
print(round(ans,7))
