#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> edge[10001]; //start to 1 index
bool visit[10001];


void initVisit();
void dfs(int v);
void bfs(int s);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M,V;
    int u,v;
    int check, tmp_v;
    cin >> N >> M >> V;
    
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(int i = 1; i <= N; i++)
        sort(edge[i].begin(), edge[i].end()); //sort ascending order
    
    initVisit();
    
    check = 0; tmp_v = V;
    dfs(V);

    cout << '\n';
    
    initVisit();
    bfs(V);
    
 

}
void initVisit(){
    for(int i = 0; i < 10001; i++)
        visit[i] = false;
}
void dfs(int v){
    if(visit[v] == true)
        return;
    cout << v << ' ';
    visit[v] = true;
    for(int i = 0; i < edge[v].size(); i++)
        dfs(edge[v][i]);
}
void bfs(int s){
    queue<int> q;
    int now, k, next;
    
    q.push(s);
    visit[s] = true;
    while(!q.empty()){
        now = q.front();
        q.pop();
        cout << now << ' ';
        for(k = 0; k < edge[now].size(); k++){
            next = edge[now][k];
            if(visit[next] == false){
                visit[next] = true;
                q.push(next);
            }
        }
    }
}
