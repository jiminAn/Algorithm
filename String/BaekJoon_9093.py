n = int(input())

for i in range(n):

    s = input()
    s_tmp = s.split(' ')

    for word in s_tmp:
        print(word[::-1], end = " ")
