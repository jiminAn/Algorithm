# Baekjoon 17371 : 이사
import sys

input = sys.stdin.readline

def euclid_dist(x1, y1, x2, y2):
    return (x2 - x1) ** 2 + (y2 - y1) ** 2


N = int(input())
f = []
min = float("inf")

for _ in range(N):
    f.append(tuple(map(int, input().split())))

for i in range(N):
    max = -1
    max_idx = -1
    for j in range(N): # i 편의시설 기준 가장 먼 편의시설 j 찾기  
        dist = euclid_dist(f[i][0], f[i][1], f[j][0], f[j][1])
        if max < dist:
            max = dist
            max_i = i
    if max < min: # i-j max값이 가장 가까운 거리보다 작을 경우 갱신 
        min = max
        min_i = max_i
        
print(f[min_i][0], f[min_i][1])
