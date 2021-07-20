import sys
input = sys.stdin.readline

find_flag = True

orig_str = input()
find_str = ["U","C","P","C"]

for ch in find_str:
    idx = orig_str.find(ch)
    if idx == -1:
        find_flag = False
        print("I hate UCPC")
        break
    orig_str = orig_str[idx:]

if find_flag:
    print("I love UCPC")
