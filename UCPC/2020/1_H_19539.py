# BaekJoon 19539
# Math, Greedy

import sys

n = int(sys.stdin.readline())
heights = list(map(int, sys.stdin.readline().split()))
heights_sum = sum(heights)
turn = heights_sum // 3 # +2 물뿌리개가 등장해야하는 횟수

if heights_sum % 3 != 0: # 전체 합이 3의 배수가 아닌 경우
    print("NO")
else:# 전체 합이 3의 배수인 경우
    for h in heights:
        turn -= h // 2
    if turn <= 0:
        print("YES")
    else:
        print("NO")
