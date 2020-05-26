#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> iPair;

#define INF 1000001//key 초기화시 저장할 무한대값
int V, E;
vector<iPair> adj[10001]; //adj벡터의 index값은 노드의 번호
void printGraph();
void addEdge(int u, int v, int weight);
void primMST();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> V >> E;

    int u,v,w;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
   // printGraph();
    primMST();
    return 0;
}
void addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
void printGraph(){
    pair<int,int> tmp;
    for(int i = 1; i <= V; i++){
        for(int j = 0; j < adj[i].size(); j++){
            tmp = adj[i][j];
            cout << '(' << tmp.first << ',' << tmp.second << ") ";
        }
        cout << '\n';
    }
}
void primMST(){
    /*
     아래 선언과 같은 표현
     priority_queue<iPair> pq : default container 는 vector, defualt order는 내림차순(less)
     */
    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;//min-heap 구현 (weight(key), vertex)
    int src = 1; // 시작 vertex
    int v, weight;
    
    vector<int> key(V+1,INF); //key값을 무한대로 초기화한 벡터 선언
    vector<int> parent(V+1,-1); //부모 노드를 표현하기 위한 벡터 선언, MST 저장
    vector<bool> inMST(V+1,false); //MST에 포함되어있는지 여부 체크하는 벡터
    
    //시작 vertex 1 queue에 push하고 key값 0으로 초기화
    pq.push(make_pair(0,src));
    key[src] = 0;
    
    while( !pq.empty() ){
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        
        for(auto x: adj[u] ){//범위 기반 for문 == in python, for i in list
            v = x.first;
            weight = x.second;
            
            if(inMST[v] == false && key[v] > weight){
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
//    for(int i = 2; i <= V; i++)//MST print
//        cout << parent[i] << '-' << i << '\n';
    int total_weight = 0;
    for(int i = 1; i <= V; i++)//MST total weight
        total_weight += key[i];
    cout << total_weight << '\n';
}


