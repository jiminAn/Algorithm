# 그래프의 최소 비용 문제(2020.05.27)
## 최소 신장 트리 문제 
: 가중치 그래프에서 모든 정점들을 연결하는 간선들의 가중치의 합이 최소가 되는 트리를 찾는 문제 

### 최소 신장 트리 문제 해결 알고리즘
#### Prim Algorithm(Vertex-based algorithm)
: 가장 weight가 작은 간선과 연결된 vertex를 추가해나가면서 최소 신장 트리를 완성  

##### 알고리즘 동작하기 위해 필요한 정보
: 두 종류의 상호 배타 집합에 관한 정보
1. 트리 정점(U) : 최소 신장 트리를 만들기 위해 선택된 정점
2. 비트리 정점(V-U) : 선택되지 않은 정점
: edge에 관한 정보
1. candidate edge : 한 정점에 연결된 모든 edge
2. 선택된 edge(set T) : candidate edge중 min-weight이며, edge에 연결된 두 노드가 서로 상호 배타인 경우

##### 알고리즘 동작 과정
1. set T를 공집합으로 초기화(size(T)= n-1)
2. U에 시작 정점을 넣기
3. U와 V-U사이에 연결된 모든 edge들은 candidate edge
4. candidate edge들 중 가장 min-weight edge를 T에 추가하고 해당 edge와 연결된 V-U에 있던 정점을 U에 넣기
5. U == V가 될때까지 즉, 모든 정점이 U에 추가될 때까지 3~4과정을 반복

##### pseudocode
Tree prim(Vertex V, Edge E){  
&nbsp;&nbsp;&nbsp;&nbsp;Vertex *U;  
&nbsp;&nbsp;&nbsp;&nbsp;Vertex u,v;  
&nbsp;&nbsp;&nbsp;&nbsp;T = {};  
&nbsp;&nbsp;&nbsp;&nbsp;U = {A};  
&nbsp;&nbsp;&nbsp;&nbsp;while( U != V){  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(u,v) = lowest cost edge with u in U and v in (V-U);  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;T += (u,v);  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;U += v;  
&nbsp;&nbsp;&nbsp;&nbsp;}  
&nbsp;&nbsp;&nbsp;&nbsp;return T;  
}  


#### Kruskal Algorithm( Edge-Oriented algorithm)
: weight가 작은 순으로 edge를 정렬한 후 cycle이 생기지 않게 edge를 추가해나가면서 최소 신장 트리를 완성
*cycle 을 체크하는 방법에 따라 두 가지 시간 복잡도를 가지게 됨
1. dfs를 사용하여 체크: O(n^2)
2. UNION_FIND 연산으로 체크: O(nlogn) --> Improved performance

##### 알고리즘 동작하기 위해 필요한 정보
1. UNION_FIND 연산 : cycle이 있는지 check하기 위해 label을 닮
- UNION: 합치면서 label을 변경  --> O(1)
- FIND : O(logn)
2. min-cost tree T: 최소 신장 트리

##### 알고리즘 동작 과정
1. G의 모든 edge들을 오름차순으로 정렬해서 list에 넣기
2. 정렬된 list에서 min-cost edge를 고르고 min-cost tree T에 추가하기
*단 edge추가시 cycle이 생기면 안됨
3. T가 n-1개의 edge를 가지거나, sorted list가 empty가 될 때가지 이 과정을 반복

##### pseudocode
Tree Kruskal(Vertex V, Edge E){  
&nbsp;&nbsp;&nbsp;&nbsp;T = {};    
&nbsp;&nbsp;&nbsp;&nbsp;sort edge in E in ascending order;  
&nbsp;&nbsp;&nbsp;&nbsp;for each vertex V in the set V  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NEW_LABEL(v);  
&nbsp;&nbsp;&nbsp;&nbsp;for each (u,v) in E, in ascending oreder of weight{  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if LABEL(u) is not equal to LABEL(V){  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;add the edge (u,v) to the tree T;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;UNION(LABEL(u), LABEL(v));  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}    
&nbsp;&nbsp;&nbsp;&nbsp;}  
&nbsp;&nbsp;&nbsp;&nbsp;return T;  
}   

#### 용어 정리
1. 신장 트리(Spanning Tree) : N개의 정점을 포함하는 무향 그래프에서 n개의 정점과 n-1개의 간선으로 구성된 트리
2. 최소 신장 트리 : 간선에 가중치를 줘서 신장 트리를 구성하는 간선의 가중치의 합이 최소인 신장 트리



## 최단 경로 문제
: 시작 정점에서 목표 정점까지 가는 간선의 가중치의 합이 최소가 되는 경로를 찾는 문제
1. 단일 시작점 최단 경로 문제
- Dijkstra Algorithm : 음의 가중치를 허용하지 않음
- Bellman-Ford Algorithm : 음의 가중치 허용, 가중치의 합이 음인 사이클은 허용하지 않음
2. 모든 쌍 최단 경로 문제
- Floyd-Warshall Algorithm

### 단일 시작점 최단 경로 문제 (Single Source Shortest Path)
:G내에 있는 한 노드로부터 다른 모든 노드로 까지의 최단거리

#### Dijkstra Algorithm 
: 시작 정점에서 거리가 최소인 정점부터 선택해 나가면서 최단 경로를 구하는 방식  
- 방향 그래프  
- 양수 가중치만을 가지는 egde  
- 시간복잡도 O(m)+O(nlogn)

#### Bellman-Ford Algorithm
: Dijkstra Algorithm 은 negative edge를 catch하지 못하는 점을 개선한 알고리즘
- 음의 edge는 허용하나 음의 cycle은 불가
- 지나간 time clock도 봄 --> 시간복잡도 O(n^2)

### 모든 쌍 최단 경로 문제 (All Pairs Shortest Path)
#### Floyd-Warshall Algorithm



### ---------------------------------적용 문제 예시--------------------------------------

* 1197번.최소 스패닝 트리 https://www.acmicpc.net/problem/1197
* 1916번.최소 비용 구하기 <https://www.acmicpc.net/problem/1916>
