#include <iostream>
#include <vector>
#include <algorithm>

int total_virus;
using namespace std;

vector<int> edge[10001]; //start to 1 index
bool visit[10001];


void initVisit();
void dfs(int v);


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    int u,v;
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(int i = 1; i <= N; i++)
        sort(edge[i].begin(), edge[i].end()); //sort ascending order
    
    initVisit();
    
    dfs(1);

    cout << total_virus-1 << '\n';

}
void initVisit(){
    for(int i = 0; i < 10001; i++)
        visit[i] = false;
}
void dfs(int v){
    if(visit[v] == true)
        return;
    total_virus++;
    visit[v] = true;
    for(int i = 0; i < edge[v].size(); i++)
        dfs(edge[v][i]);
}
