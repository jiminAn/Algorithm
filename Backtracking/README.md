## Backtracking (2020.05.07 | 2020.08.12)
## 백트래킹 기법이란?
초기 상태에서 목표 상태로 가는 경로를 탐색하는 기법으로, 해가 아니면 되돌아가서 다시 해를 찾는 방법이다  
이 기법을 사용하여 최적화 문제와 결정 문제 해결 가능  

상태 공간 트리에 기반하여 탐색을 수행한다  

상태 공간 트리란?
1. 해를 찾기 위한 과정을 트리로 표현
2. 내부 노드는 최종상태로 가는 중간 상태의 표현
3. 단말 노드는 하나의 후보해에 대한 최종 상태
4. 트리를 깊이 우선 탐색하는 방법이 백트래킹 알고리즘의 기본 형태

최적화(Optimization) 문제란?  
문제에 대한 최소값 혹은 최대값을 찾는 것  

결정(Decision) 문제란?  
문제의 조건을 만족하는 해의 존재 여부를 yes,no로 답하는 문제

### 깊이 우선 탐색과 백트래킹의 차이
트리에서 깊이 우선 탐색 방법이 백트래킹 알고리즘의 기본 형태이나 두 방식에는 차이점이 존재한다  
깊이우선 탐색은, 모든 경로를 다 탐색하나 백트래킹은 가지치기로 불필요한 경로를 조기에 차단시킨다.  
또한 깊이 우선 탐색은 경우의 수가 너무 많을 경우 처리가 불가능하나 백트래킹은 일반적으로 경우의 수가 줄어 처리 가능하다  
단! 최악의 경우 백트래킹에서도 시간복잡도가 지수 함수를 요하여 처리 불가능 할 수 있다
  

### 백트래킹 기법 적용 문제 예시
1. 미로찾기  
-1) 미로의 입구에서 출구까지 가는 경로의 존재 유무-> 결정 문제  
-2) 입구에서 출구까지 가는 최단경로 찾기 -> 최적화 문제  
2. n-Queen
3. Map coloring
4. 부분 집합의 합(Subset Sum)문제  
-1) 원소의 합이 조건에 맞는 부분 집합 존재-> 결정 문제  
-2) 원소의 개수가 최대인 부분 집합을 찾는 문제-> 최적화 문제  

### ---------------------------------적용 문제 예시--------------------------------------
#### 부분집합
백트래킹 기법으로 power set 구하기
파워셋 : 어떤 집합의 공집합과 자기자신을 포함한 모든 부분집합으로 집합의 원소의 개수가 n일 때 총 부분집합의 개수는 2^n 이다  
- n개의 비트열을 사용하여 부분집합을 표현해 1 또는 0 값을 가지는 항목들로 구성된 n개의 배열을 만들어보자  
-비트열 배열의 i번 인덱스 값은 집합희 i번 인덱스 원소의 부분 집합 포함 여부를 표현한다.  
부분 집합 상태 공간 트리
-선택지가 항상 2개이므로 자식 노드가 2개인 이진트리 형태
-단말 노드 개수 = 2^n
-왼쪽 식을 방문하는 경우는 원소를 포함하지 않는 선택(0)
-오른쪽 자식을 방문하는 경우는 원소를 포함하는 선택(1)


#### 순열
순열 상태의 공간 트리를 사용
-n개의 원소에 대한 부분집합과 순열의 상태 공간 트리의 높이는 동일하다
-순열의 경우에는 선택을 할 때마다 가능한 선택지가 감소  
탐욕 알고리즘으로도 해결 가능!

#### 동전 거스름돈 문제
최소 동전 갯수로 잔돈을 거슬러주자



### 백트래킹 문제
* 9663번.n-Queen https://www.acmicpc.net/problem/9663


### etc
* 14888번.연산자 끼워넣기 https://www.acmicpc.net/problem/14888
* 5585번.거스름돈 <https://www.acmicpc.net/problem/5585>
