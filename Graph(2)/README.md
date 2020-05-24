# 그래프의 최소 비용 문제(2020.05.27)
## 최소 신장 트리 문제 
: 가중치 그래프에서 모든 정점들을 연결하는 간선들의 가중치의 합이 최소가 되는 트리를 찾는 문제 

### 최소 신장 트리 문제 해결 알고리즘
#### Prim Algorithm( Vertex-based algorithm)
: 가장 weight가 작은 간선과 연결된 vertex를 추가해나가면서 최소 신장 트리를 완성  

##### 알고리즘 동작하기 위해 필요한 정보
: 두 종류의 상호 배타 집합에 관한 정보
1. 트리 정점(U) : 최소 신장 트리를 만들기 위해 선택된 정점
2. 비트리 정점(V-U) : 선택되지 않은 정점
: edge에 관한 정보
1. candidate edge : 한 정점에 연결된 모든 edge
2. 선택된 edge(set T) : candidate edge중 min-weight이며, edge에 연결된 두 노드가 서로 상호 배타인 경우

#### 알고리즘
1. set T를 공집합으로 초기화(size(T)= n-1)
2. U에 시작 정점을 넣기
3. U와 V-U사이에 연결된 모든 edge들은 candidate edge
4. candidate edge들 중 가장 min-weight edge를 T에 추가하고 해당 edge와 연결된 V-U에 있던 정점을 U에 넣기
5. U == V가 될때까지 즉, 모든 정점이 U에 추가될 때까지 3~4과정을 반복

#### pseudocode
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




#### Kruskal Algorithm

#### 용어 정리
1. 신장 트리(Spanning Tree) : N개의 정점을 포함하는 무향 그래프에서 n개의 정점과 n-1개의 간선으로 구성된 트리
2. 최소 신장 트리 : 간선에 가중치를 줘서 신장 트리를 구성하는 간선의 가중치의 합이 최소인 신장 트리



## 최단 경로 문제
: 시작 정점에서 목표 정점까지 가는 간선의 가중치의 합이 최소가 되는 경로를 찾는 문제



### ---------------------------------적용 문제 예시--------------------------------------




### 백트래킹 문제
* 9663번.n-Queen https://www.acmicpc.net/problem/9663


### etc
* 14888번.연산자 끼워넣기 https://www.acmicpc.net/problem/14888
* 5585번.거스름돈 <https://www.acmicpc.net/problem/5585>
