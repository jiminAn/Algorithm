# 문자열 조작(String Manipulation)

2021-04-11 (파이썬 알고리즘 인터뷰 6장)

### 목차

문제01. 유효한 펠린드롬

문제02. 문자열 뒤집기

문제03. 로그 파일 재정렬

문제04. 가장 흔한 단어

문제05. 그룹 애너그램

문제06. 가장 긴 펠린드롬 부분 문자열 



## 6장 문자열 조작

문자열을 변경하거나 분리하는 등의 여러과정을 말함

------

### 1. 유효한 펠린드롬

주어진 문자열이 펠린드롬인지 확인하라 단, 대소문자 구분x, 영문자와 숫자만을 대상으로 함

```python
>>> "A man, a plan, a canal: Panama"
True
>>> "race a car"
False
```

**리스트로 구현한 펠린드롬 체크 함수**

- 리스트의 경우 pop()을 하게되면 O(n)이 소요됨

```python
def isPalindrome(s):
    strs = []

    #input preprocessing
    for ch in s:
        if ch.isalnum():
            strs.append(ch.lower())

    while len(strs) > 1:
        if strs.pop(0) != strs.pop():
            return False
    return True
```

[백준 기본 펠린드롬 문제 10174](https://www.acmicpc.net/problem/10174)

### 2. 문자열 뒤집기

[백준 기본 문자열 뒤집기 문제 9093](https://www.acmicpc.net/problem/9093)



