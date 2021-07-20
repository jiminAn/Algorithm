#include <iostream>
#include <vector>
#include <queue>
#define MAXSIZE 500002
using namespace std;

vector<int> edge[MAXSIZE];
int visited[MAXSIZE];
int leaf_levels;

void bfs();

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, T;
    cin >> N;
    T = N - 1;
    while(T--){
        int n1, n2;
        cin >> n1 >> n2;
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }
    bfs();
    if (leaf_levels % 2 == 1)
        cout << "Yes\n";
    else
        cout << "No\n";
}
void bfs(){
    visited[1] = 1;
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){// 1 < 8
        bool leaf = true;
        int cur = q.front(); q.pop(); // 1
        
        for(auto next : edge[cur]){// 8, 4, 3
            if (visited[next] == 0){
                visited[next] = visited[cur] + 1;
                leaf = false;
                q.push(next);
            }
        }
        if (leaf){
            //cout << "cur" << cur << " leaf levels" << visited[cur] -1 << '\n';
            leaf_levels += visited[cur] - 1;
        }           
    }
}
