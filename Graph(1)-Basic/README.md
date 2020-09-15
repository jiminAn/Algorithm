# Graph(1)-Basic (2020.05.20),(2020.09.16)
[##_Image|kage@couadN/btqIPQUeQg9/dJDCPAc3etsqZJ1S7kpuZ1/img.png|alignCenter|data-origin-width="0" data-origin-height="0" data-ke-mobilestyle="widthContent"|||_##]

(본 강의 노트는 SW Expert Academy의 Programming Advanced 강의를 기반으로 하고 있습니다)


# 그래프의 기본과 탐색
# 1차시. 그래프의 기본과 탐색
## 1) 소개
### Graph란?
객체들과 이들 사이의 연결관계를 표현하는 것으로 정점(Vertex,Node)들의 집합과 이들을 연결하는 간선(Edge)들의 집합으로 구성된 자료구조  
- G = (V,E), V: 정점들의 집합, E: 간선들의 집합
- 선형 자료구조, 트리 자료구조로 표현하기 어려운 다대다 관계를 가지는 원소들을 표현하기에 용이

### Graph의 종류
1. Undirected Graph ( 무향 그래프 ) 
: 서로 대칭적인 관계를 연결해서 나타낸 그래프 
- ex : 친구 관계를 나타낸 그래프
- ex : 페이스북 친구 관계

2. Directed Graph ( 유향 그래프 )  
: 간선을 화살표로 표현, 방향성의 개념이 포함됨  
- ex : 기업간 공급 관계, 작업의 선후 관계 등 표현 가능  
- ex : 인스타그램 팔로우-팔로잉 관계

3. Weighted Graph ( 가중치 그래프 )  
: 이동하는데 드는 비용을 간선에 부여한 그래프 
- ex : 도시 사이의 이동 비용을 나타낸 그래프

### Graph 용어 설명
1. Adjacency ( 인접 )  
: 두 개의 정점이 간선으로 연결되면 서로 인접해 있다고 함  
- *주의: 무향 그래프와 유향 그래프에서의 인접 정점의 기준은 다름. 
- 전자는 간선에 방향성이 없으므로 하나에 간선에 연결된 두 정점은 반드시 인접 정점이나
- 후자의 경우 간선에 방향성이 있으므로 1->2 일 경우, 2정점은 1번의 인접정점이나, 1정점은 2번 정점의 인접정점이 아님  
- 완전 그래프 : 모든 정점들이 서로 인접해 있는 그래프
- 부분 그래프 : 원래 그래프에서 일부의 정점이나 간선을 제외한 그래프

2. 경로 
: 간선들을 순서대로 나열 한 것  
- ex : 간선(0,2), (2,4), (4,6) 경로: 0->2->4->6  
- 단순 경로 : 경로 중 한 정점을 최대한 한 번만 지나는 경로
- 사이클 : 시작한 정점에서 끝나는 경로


## 2) Graph 표현
### 그래프 표현 방식
1. Adjacent Matrix ( 인접 행렬 )  
: |V|x|V| 크기의  정방 행렬로, 2차원 배열을 이용해서 간선 정보를 저장  
- 행 번호와 열 번호는 그래프의 정점에 대응하며 두 정점이 인접되어 있으면 1, 그렇지 않으면 0으로 표현
- 인접 행렬의 단점: 정점의 개수 n이 커지면 필요한 메모리 크기는 n^2에 비례해서 커짐-> 인접 리스트로 해결 가능

**2. Adjacent List ( 인접 리스트 )**  
: 각 정점마다 인접 정점으로 나가는 간선의 정보를 연결리스트에 저장
- 각 정점에 대한 인접 정점을 개수만큼 저장하고 각각 노드로 하는 리스트로 저장함 
- 노드 수 = 간선의 수, 각 정점의 노드 수 = 정점의 진출 차수
- 인접 리스트의 장점: 불필요한 메모리 사용과 비용 절감 가능
- 코드
```
#include <vector>
vector<int> edge[10000];
for( int i = 0; i < edge_len; i++){
	scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
}
```

3. 간선의  배열
: 간선(시작 정점, 끝 정점)을 배열에 연속적으로 저장함
- 상대적으로 간선의 수가 적을 때 사용하는 방법
  
  
# 2차시. 그래프 탐색
## 1) 소개
### Graph 순회   
: 비선형적 구조인 그래프로 표현된 모든 정점을 빠짐없이 탐색하는 것
1. Depth First Search
- 깊이 우선 탐색
- stack, 재귀호출을 사용하여 구현
- 코드
```
void dfs(int v){
	if( visit[v] == true )
    	return;
    printf("%d ", v); //print the visited vertex
    for(int i = 0; i < edge[v].size(); i++)
    	dfs(edge[v][i]);
}
```

2. Breadth First Search
- 너비 우선 탐색
- queue를 사용하여 구현  
- BFS를 활용하여 최단거리를 구할 수 있음
- 코드
```
#include <queue>
void bfs(int s){
	queue<int> q;
    int now, k, next;
    q.push(s);// 's' node is start vertex
    visit[s] = true;
    while( !q.empty() ){
    	now = q.front();
        q.pop();
        printf("%d ", now); //print the visited vertex
        for( k = 0; k < edge[now].size(); k++){ //visit adjacent vertex in 'now' node
        	next = edge[now][k];
            if( visit[next] == false ){
            	visit[next] = true;
                q.push(next);
            }
        }
}
```

# 3차시. 상호배타 집합들
## 1) 소개
### 상호배타 집합들(서로소)
: 서로 중복 포함된 원소가 없는 집합, 교집합이 없는 집합  

### 상호배타 집합 표현방법  
1. 연결 리스트
- 같은 집합의 원소들은 하나의 연결리스트로 관리함
- 연결리스트의 첫 번째 원소를 집합의 대표 원소로 삼음
- 각 원소는 집합의 대표 원소를 가리키는 링크를 가짐 
2. 트리 : 연결리스트보다 효율적임
- 하나의 집합을 하나의 트리로 표현
- 자식 노드가 부모 노드를 가리키며 루트 노드가 집합의 대표자가 됨
- 문제점: 편향트리구조가 될 가능성이 있음


### 상호배타 집합 연산  
1. Make set: 원소 x 만으로 구성된 집합을 생성하는 연산
2. Find set: 임의의 원소 x가 속한 집합을 알아내기 위해 사용, 집합의 대표자를 알기 위한 연산  
- 집합의 대표자란? 집합을 구분하는 특정원소를 대표자라고 함  
3. Union : 원소 x가 속한 집합과 y가 속한 집합이 하나의 집합으로 합쳐지는 연산


