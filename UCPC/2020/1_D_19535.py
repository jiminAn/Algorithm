# Baekjoon 19535
import sys
from collections import defaultdict
input = sys.stdin.readline

def NCombination3(n):
    denominator = 1
    for k in range(n, n-3, -1):
        denominator *= k
    return denominator // 6

N = int(input())
graph = defaultdict(list)

for _ in range(N-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

d_trees = g_trees = 0

for i in range(1, N+1):
    linked_nodes = len(graph[i])
    # 연결된 정점이 3개 이상인 경우
    if linked_nodes >= 3:
        g_trees += NCombination3(linked_nodes)
    # 연결된 정점이 2개 이상인 경우
    if linked_nodes >= 2:
        for next_node in graph[i]:
            next_linked_nodes = len(graph[next_node])
            if next_linked_nodes >= 2:
                d_trees += (linked_nodes - 1) * (next_linked_nodes -1)

d_trees //= 2 # 중복 트리 제거
if d_trees >g_trees * 3:
    print('D')
elif d_trees < g_trees * 3:
    print('G')
else:
    print('DUDUDUNGA')
