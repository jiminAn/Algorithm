import sys
input = sys.stdin.readline

N = int(input()) # 10
change_point = N - 1 # 9
max_interval = N - 1
ans = 1

while(change_point > 0): # 9 # 4
    if N % change_point  == 0:
        tmp_ans = int(N / change_point)
    else:
        tmp_ans = int(N / change_point) + 1
    same_sec = (change_point - int(max_interval/tmp_ans))  # (9 - 9/2) = 5, (4 -9/3) = 1
    ans += tmp_ans * same_sec # ans = 1 + 2*5 = 11 # ans = 11 + 3 * 1
    #print('tmp_ans:', tmp_ans, 'same_sec:', same_sec, 'ans:', ans)
    change_point -= same_sec #  9 - 5 = 4

print(ans)
