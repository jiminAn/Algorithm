#include <iostream>
#include <queue>

using namespace std;


int maze[101][101]; // start (1,1)index
int dist[101][101];
int n, m;
int ans;

void bfs(int row, int column);
void initDist();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int idx;
    string tmp;
    cin >> n >> m;
    
    for(int i = 1; i <=n; i++){
        idx = 0;
        cin >> tmp;
        for(int j = 1; j <=m; j++){
            maze[i][j] = int(tmp[idx++])-48;
        }
        
    }
    
      

    initDist();
    bfs(1,1);
    
    cout << ans+1 << '\n';
    
    
    return 0;
}
void bfs(int r, int c){
    
    queue<pair<int,int>> q;
    pair<int,int> now,next;

    q.push(make_pair(r,c));
    dist[r][c] = 0;
    
    while(!q.empty()){
        now = q.front();
        q.pop();

        if( now.first-1 >= 1 && maze[now.first-1][now.second] == 1){//up
            next = make_pair(now.first-1,now.second);
            if(dist[next.first][next.second] == -1){
                dist[next.first][next.second] = dist[now.first][now.second] + 1;
                q.push(next);
            }
        }
        if( now.first+1 <= n && maze[now.first+1][now.second] == 1){//down
            next = make_pair(now.first+1,now.second);
            if(dist[next.first][next.second] == -1){
                dist[next.first][next.second] = dist[now.first][now.second] + 1;
                q.push(next);
            }
        }
        if( now.second-1 >= 1 && maze[now.first][now.second-1] == 1){//left
            next = make_pair(now.first,now.second-1);
           if(dist[next.first][next.second] == -1){
                dist[next.first][next.second] = dist[now.first][now.second] + 1;
                q.push(next);
            }
        }
        if( now.second+1 <= m && maze[now.first][now.second+1] == 1){//right
            next = make_pair(now.first,now.second+1);
            if(dist[next.first][next.second] == -1){
                dist[next.first][next.second] = dist[now.first][now.second] + 1;
                q.push(next);
            }
        }
        
    }
    ans = dist[n][m];
}
void initDist(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <=m; j++)
            dist[i][j] = -1;
}
