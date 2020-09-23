# 그래프의 최소 비용 문제(2020.05.27) | (2020.09.16)
(본 강의 노트는 SW Expert Academy의 Programming Advanced 강의를 기반으로 하고 있습니다)

# 그래프의 최소 비용 문제

## 1차시. 최소 신장 트리

### 문제 유형

1.  최소 신장 트리 문제

-   가중치 그래프에서 모든 정점들을 연결하는 간선들의 가중치의 합이 최소가 되는 트리를 찾는 문제

2.  최단 경로 문제

-   시작 정점에서 목표 정점까지 가는 간선의 가중치의 합이 최소가 되는 경로를 찾는 문제

### 신장트리란(Spanning Tree)?

: N개의 정점을 포함하는 무향 그래프에서 N개의 정점과 N-1개의 간선으로 구성된 트리

### 최소 신장 트리란(Minimum Spanning Tree)?

: 간선에 가중치를 줘서 신장 트리를 구성하는 간선의 가중치의 합이 최소인 신장 트리

-   최소 신장 트리를 찾는 알고리즘: 프림, 크루스칼 알고리즘

## 2차시. 프림 알고리즘(Vertex oriented Algotirhm )

### 프림알고리즘이란?

: 한 정점에 연결된 간선들 중 최소 간선을 가진 정점을 선택해나가며 최소 신장 트리를 만들어가는 방식

1.  임의의 정점을 하나 선택해서 시작
2.  선택한 정점들과 인접하는 정점들 중에 최소 비용의 간선이 존재하는 정점을 선택
3.  선택한 간선의 개수가 n-1개가 될 때 까지 이를 반복(단, 정점의 개수는 n개)

### 프림 알고리즘을 동작하기 위해 필요한 정보

: 두 종류의 상호 배타 집합에 관한 정보

1.  트리 정점(Tree vertices)

-   최소 신장 트리를 만들기 위해 선택된 정점

2.  비트리 정점 (non-tree verticies)

-   선택되지 않은 정점

### 코드

```
MST_PRIM(G,r) // G : graph, r : start vertex
    /* initialize U.key and U.parent */
    FOR ALL u in G.v // G.v : set of vertecies
        u.key = MAX_VALUE // u.key : u is a edge that minimum weight connected to U
        u.parent = NULL // u.parent : parent of U in tree
    r.key = 0
    Q = G.v // put in Q, all the vertecies (Q is priority queue)
    WHILE Q is not empty
        u = Extract_MIN(Q) // bring key that has minimum value in Q
        FOR ALL v in ADJ(G,u) // ADJ : Adjacent vertecies
            IF v in Q AND weight(u,v) < v.key
                v.parent = u
                v.key = weight(u,v) // renew the distance with tree
```

-   해당 함수 종료 시, parent에 저장되어 있는 정보가 최소신장트리에 해당

## 3차시. 크루스칼 알고리즘( Edge oriented Algorithm )

### 크루스칼 알고리즘이란?

: 최소 가중치 간선을 하나씩 선택해서 최소 신장 트리를 찾는 알고리즘

-   단, 사이클이 생기지 않아야 한다.
-   N개의 상호 배타 집합이 존재함
-   간선을 선택하면 간선의 두 정점이 속한 트리가 연결되어 하나의 집합으로 됨
-   선택한 간선의 두 정점이 이미 연결된 트리에 속하는 정점이면 사이클이 생김

### 크루스칼 알고리즘의 동작 과정

1.  최초 모든 간선을 가중치에 따라 오름차순으로 정렬
2.  가중치가 가장 낮은 간선부터 선택하면서 트리를 증가시킴

-   사이클이 존재하면 다음으로 가중치가 낮은 간선 선택

3.  n-1 개의 간선이 선택될 때까지 앞의 과정 반복

### 코드

```
MST_KRUSKAL(G)
    T = empty_set
    FOR ALL v in G.v
        Make_set(v)
    sort(G.e.start, G.e.end) // default is ascending order

    WHILE T.size() < |V| - 1
        u = Extract_MIN(G.e) // choose the edge that has minimum weight
        IF Find_set(U) != Find_set(v)
            T = T UNION {(u,v)}
            Union(u,v)
    RETURN T
```

### 크루스칼 알고리즘의 특징

1.  간선 선택 과정에서 생성되는 트리를 관리하기 위해 상호 배타 집합 사용

-   트리에 속한 노드들을 자신을 루트로 하는 서브 트리의 높이를 랭크라는 이름으로 저장함

2.  선택한 간선으로 두 개의 트리가 한 개의 트리로 합쳐질 때 각 트리에 해당하는 상호 배타 집합을 Union연산으로 합침
3.  랭크 값이 작은 트리를 랭크 값이 큰 트리의 서브 트리로 포함시키게 되면 트리에 포함된 노드들의 랭크 값을 수정할 필요가 없음

## 4차시. 최단

### 최단경로란?

: 간선의 가중치가 있는 유향 그래프에서 두 정점 사이의 경로들 중에 간선의 가중치의 합이 최소인 경로

### 단일 시작점 최단 경로 문제

1.  다익스트라 알고리즘

-   음의 가중치를 허용하지 않음

2.  벨만-포드 알고리즘

-   음의 가중치 허용, 단, 음의 사이클은 허용하지 않음

### 모든 쌍 최단 경로 문제

1.  플로이드-워샬 알고리즘

## 5차시. 다익스트라 알고리즘

### 다익스트라 알고리즘이란?

: 시작 정점에서 거리가 최소인 정점부터 선택해 나가면서 최단 경로를 구하는 방식

-   탐욕 기법을 사용한 알고리즘으로 최소신장 트리를 구하는 프림알고리즘과 유사

### 탐욕적 방법으로 정점 선택하기

: 집합 S에 포함되지 않은 v를 집합 S에 포함시킬 때

-   정점 v까지의 최단 경로: d\[u\] + w(u,v)
-   P'+ w(x,y) <= P
-   d\[u\] + w(u,v) <= P'+ w(x,y)
-   만약 위의 식이 거짓이라면, 정점 v대신 y를 선택해야 함

### 코드

```
// G : graph, r : start vertex, s : set of chosen vertecies
// D : distance for all chosen vertecies weight == value of minimum path
// P : Minimum Path tree
// ADJ(u) : adjacent vertecies at U
Dijkstar(G,r)
    s = empty_set // initialize set S
    FOR ALL v in V
        D[v] = MAX_VALUE
        P[v] = NULL
    D[r] = 0

    WHILE S != V
        select u in V-S that Vertex has minimum D[u]
        S = S UNION {u}
        FOR ALL v in ADJ(u)
            IF v in V - S and D[u] + weight(u,v)
                D[v] = D[u] + weight(u,v)
                P[v] = u
```

### 음의 가중치가 있을 경우

: 이미 선택한 정점에 대해서는 다시 방문하지 않으므로, 음의 가중치가 있어도 이를 갱신하지 못해 음의 가중치가 있을 경우 다익스트라 알고리즘으로는 최단 경로를 찾을 수 없음

### 벨만-포드 알고리즘

: 음의 가중치를 포함하는 그래프에서 최단 경로를 구할 수 있음

-   가중치의 합이 음인 싸이클은 허용하지 않음
-   다익스트라로 최단 경로를 구할 수 있다면 벨만-포드로도 구할 수 있음

1.  출발점에서 각 정점까지 간선 하나로 구성된 경로 고려, 최단 경로를 구함
2.  최대 간선 2개까지 고려, 최단 경로 구함
3.  최대 간선 N-1개 까지 고려한 경로들에서 최단 경로 구함
4.  다익스트라 알고리즘에 비해 시간이 많이 소요됨

-   다익스트라는 한 번 방문한 정점은 다시 방문하지 않지만, 벨만-포드는 음의 가중치를 찾아야하기 때문에 방문한 정점도 다시 방문
