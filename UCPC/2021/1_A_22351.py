import sys
input = sys.stdin.readline

S = input().strip()
N = len(S)

if N == 1: # 길이가 1인 문자열은 예외 처리
    print(S[0], S[0], sep=' ')
    exit(0)

for i in range(1,4): # 1,2,3자리 수
    step = i # 2
    s, e = 0, i
    next_flag = True
    cur = int(S[0:i]) #
    while e < N:
        if cur % int('9'*step) == 0: # 끝자리일 경우 자리수 증가
            step += 1
        s = e
        e = e + step
        next = int(S[s:e])
        if cur + 1 != next:
            next_flag = False
            break
        cur = next
    if next_flag:
        break

A = int(S[0:i])
B = int(next)

if A < B:
    print(A, B, sep=' ')
else:
    print(A, A, sep=' ')
