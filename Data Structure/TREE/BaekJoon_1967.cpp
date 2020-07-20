#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
 
int n;
bool visited[10001];
vector<pair<int,int>> node[10001];
 
int ans; //지름 길이
int end_point; //지름에 해당하는 끝점
void dfs(int point,int length);
void init_visit();
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    int parent,child,length;
    
    for(int i = 0; i < n-1; i++){//그래프에서의 입력 방식과 동일하게 받음
        cin >> parent >> child >> length;
        node[parent].push_back(make_pair(child,length));
        node[child].push_back(make_pair(parent,length));
    }
    
    //가장 멀리 있는 정점(end_point) 구하기
    init_visit();
    dfs(1,0);
    
    //end_point와 가장 멀리 있는 정점과의 거리 구하기
    init_visit();
    dfs(end_point,0);
    cout << ans << '\n';
    
 
    return 0;
}
void init_visit(){
    for(int i = 1; i <= 10000; i++)
        visited[i] = false;
}
void dfs(int point,int length){
    
    if(visited[point])
        return;
    
    visited[point] = true;
    if(ans < length){
        ans = length;
        end_point = point;
    }
    
    for(int i = 0; i < node[point].size(); i++){
        dfs( node[point][i].first, length+node[point][i].second);
    }
}
