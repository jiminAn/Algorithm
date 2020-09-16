#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0,};
int n,m;
int box[1000][1000];
queue<pair<int,int>> start_point;
int tmp, bfs_tmp;
int day;
bool already_ripe;

void bfs(int row, int column);
bool check_unripe_tomato();

int main(void){
    pair<int,int> now;
    bool already_ripe = true;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &box[i][j]);
            if( box[i][j] == 1 )
                start_point.push(make_pair(i, j));
            if( already_ripe && box[i][j] == 0)
                already_ripe = false;
        }
    }
    if( already_ripe ){
        cout << 0 << '\n';
        return 0;
    }
    tmp = start_point.size();
    while( !start_point.empty() ){
        now.first = start_point.front().first;
        now.second = start_point.front().second;
        start_point.pop();
        bfs(now.first, now.second);
        bfs_tmp++;
        if( bfs_tmp == tmp ){
            day++;
            bfs_tmp = 0;
            tmp = start_point.size();
        }
    }
    if( !check_unripe_tomato() )
        cout << day-1 << '\n';
    else
        cout << -1 << '\n';
    
}
void bfs(int r, int c){
    
    int nx, ny;
    for(int i = 0; i < 4; i++){
        ny = r + dy[i];
        nx = c + dx[i];
        if( ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if( box[ny][nx] == 0 ){
            box[ny][nx] = 1;
            start_point.push(make_pair(ny, nx));
        }
    }
}
bool check_unripe_tomato(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if( box[i][j] == 0 )
                return true;
    return false;
}

