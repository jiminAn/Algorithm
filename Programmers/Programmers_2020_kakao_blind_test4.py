from collections import defaultdict # dict의 value의 default값 설정
from bisect import bisect_left, bisect_right # 이진탐색

def count_by_range(lst, start, end):
    # start~end 사이 값을 갖는 요소의 개수 반환
    return bisect_right(lst, end) - bisect_left(lst, start)

def solution(words, qeuries):
    ans = [] # 결과값 저장
    
    # dict의 value값을 list자료형으로 default 설정
    candidates = defaultdict(list)
    r_candidates = defaultdict(list)
    
    # 길이별 저장 
    # dict = {len(word) : [w1, w2,..., wn]}
    for w in words:
        candidates[len(w)].append(w)
        r_candidates[len(w)].append(w[::-1]) # 문자열을 뒤집어서 저장
    
    # 정렬 O(NlogN)
    # value값을 기준으로 오름차순 정렬
    for candidate in candidates.values():
        candidate.sort()
    for r_candiate in r_candidates.values():
        r_candiate.sort()
        
    # 탐색 O(N * logM)
    for q in qeuries:
        if q[0] == '?': # 와일드 카드가 접두사일 때
            lst = r_candidates[len(q)] #길이가 q와 같은 후보들을 list에 저장
            start, end = q[::-1].replace('?','a'), q[::-1].replace('?','z')
        else: # 와일드 카드가 접미사 일 때                    
            lst = candidates[len(q)]
            start, end = q.replace('?','a'), q.replace('?','z')
        ans.append(count_by_range(lst, start, end))

    return ans
