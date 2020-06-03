#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321 // ?? 왜 최대값을 문제 cost 최대값인 100001로하면 틀리고 이 값으로 하면 맞지? -> 이유: 이 무한대는 dist합으로 해야되므로 충분히 커여됨 ㅇㅇ
using namespace std;
typedef pair<int,int> iPair;

int N, M;
int start_v, end_v;
vector<iPair> adj[100001]; //adj벡터의 index값은 노드의 번호
void printGraph();
void dijkstarSP();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;

    int u,v,w;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));//방향 그래프
    }
    cin >> start_v >> end_v;
    //printGraph();
    dijkstarSP();
    return 0;
}
void printGraph(){
    pair<int,int> tmp;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < adj[i].size(); j++){
            tmp = adj[i][j];
            cout << '(' << tmp.first << ',' << tmp.second << ") ";
        }
        cout << '\n';
    }
}
void dijkstarSP(){
    int u,v,weight;
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(N+1,INF);
    pq.push(make_pair(0, start_v));
    dist[start_v] = 0;
      
    while( !pq.empty()){
        u = pq.top().second;
        pq.pop();
        
        for(auto x : adj[u]){
            v = x.first;
            weight = x.second;
            
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
//    for(int i = 1; i <= N; i++)
//        cout << "Vertex " << i << " Distance from Source " << start_v << " : " << dist[i] << '\n';
    cout << dist[end_v] << '\n';
    
    
}
