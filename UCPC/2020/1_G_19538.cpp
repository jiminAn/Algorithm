// Baekjoon 19538
// bfs
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_SIZE 200002

using namespace std;
vector<int> edge[MAX_SIZE];
int visit[MAX_SIZE];

void initVisit(int len);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int V, v;
    int start_num, start;
    int cur, next, node;
    int cnt, next_node_size;
    queue<int> Q, SQ;
    
    cin >> V;
    for(int i = 1; i <= V; i++){// save graph as adjacent list
        while(true){
            cin >> v;
            if(v == 0)
                break;
            edge[i].push_back(v);
            
        }
    }
    initVisit(V);
    cin >> start_num;
    for(int i = 0; i < start_num; i++){
        cin >> start;
        visit[start] = 0;
        Q.push(start); // inital values push in Q for using BFS
    }
    while(!Q.empty()){
        cur = Q.front(); // 1
        Q.pop();
        for(int i = 0; i < edge[cur].size(); i++){ // 1 -> 2, 3
            next = edge[cur][i];
            if(visit[next] != -1)// already visited node
                continue;
            cnt = 0;
            
            next_node_size = int(edge[next].size());
            for(int j = 0; j < next_node_size; j++){ // 2 -> 1, 3 | 3 -> 1,2,4
                if(visit[edge[next][j]] != -1) // counting visited node
                    cnt++;
            }
            if(next_node_size <= cnt * 2){ // half of neighbor node infected -> infect this node
                SQ.push(next); // push 2
            }
        }
        if(Q.empty()){
            while(!SQ.empty()){
                node = SQ.front();
                SQ.pop();
                visit[node] = visit[cur] + 1;
                Q.push(node);
                
            }
        }
    }
    for(int i = 1; i <= V; i++)
        cout << visit[i] << ' ';

}
void initVisit(int len){
    for(int i = 1; i <= len; i++){
        visit[i] = -1;
    }
}

