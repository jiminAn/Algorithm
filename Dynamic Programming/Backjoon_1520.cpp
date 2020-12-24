#include <iostream>

using namespace std;

int n, m;
int road[501][501], dp[501][501];
//right,up,left,down
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int dfs(int row, int col);
void init_dp();

int main(){
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &road[i][j]);
 
    init_dp();// -1로 초기화
    //cout << "(0,0)->";
    ans = dfs(0, 0);
    cout << ans << '\n';
    return 0;
}

int dfs(int r, int c){
    if (dp[r][c] != -1)//값이 이미 있는 경우
        return dp[r][c];
    if (r < 0 || r >= n || c < 0 || c >= m)//없는 좌표
        return 0;
    if (r == n-1 && c == m-1)//끝 점까지 도달할 경우 내리막길+1
        return 1;
 
    dp[r][c] = 0;
    for (int i = 0; i < 4; i++){ // right,up,left,down
        int nextX = r + dx[i], nextY = c + dy[i];
        if (road[nextX][nextY] < road[r][c])// 내리막길일경우 ok
            //cout << "(" << nextX << "," << nextY << ")->";
            dp[r][c] += dfs(nextX, nextY);
    }
    return dp[r][c];
}
void init_dp(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dp[i][j] = -1;
}
 

