# Baekjoon 15903 : 카드 합체 놀이
import sys
input = sys.stdin.readline
import heapq

n, m  = map(int, input().split())
cards = list(map(int, input().split()))
heapq.heapify(cards) #min heap


for _ in range(m):
    card1 = heapq.heappop(cards)
    card2 = heapq.heappop(cards)
    
    new = card1 + card2
     
    heapq.heappush(cards, new)
    heapq.heappush(cards, new)
    
print(sum(cards))
