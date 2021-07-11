# Baekjoon 17367 : 우유가 넘어지면?
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
rotat = [[0] * N for _ in range(M)]  # init 2-D

sym = {
    '.': '.',
    'O': 'O',
    '-': '|',
    '|': '-',
    '/': '\\',
    '\\': '/',
    '^': '<',
    '<': 'v',
    'v': '>',
    '>': '^'
}

for i in range(N):
    ln = input()
    for j in range(M):
        rotat[M - j - 1][i] = sym[ln[j]]

for ln in rotat:
    print(''.join(ln))
