#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<double, double>> star;
vector<vector<double>> edge;
int *parent;

double calc_dist(int i,int j);
bool compare(vector<double> a, vector<double> b);
int find(int i);
void Union(int x, int y);
bool isCycle(int src, int dest);

int main(void){
    double x,y,d;
    int edge_n = 0;
    int cnt = 0;
    double ans = 0.0;
    cin >> n;
    parent = new int[n];
    // 노드 저장
    for(int i = 0; i < n; i++){
        scanf("%lf %lf", &x, &y);
        star.push_back(make_pair(x,y));
    }
    // 노드들의 가중치 저장
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            d = calc_dist(i,j);
            edge.push_back(vector<double>());
            edge[edge_n].push_back(i);
            edge[edge_n].push_back(j);
            edge[edge_n++].push_back(d);
        }
    }
    // 조상 노드 초기화
    for(int i = 0; i < n; i++)
        parent[i] = -1;
    //엣지 가중치 오름차순 정렬
    sort(edge.begin(), edge.end(),compare);
    // 크루스칼 알고리즘
    for(int i = 0; i < edge.size(); i++){
        if( !isCycle( (int)edge[i][0], (int)edge[i][1] ) ){
            ans += edge[i][2];
            cnt++;
            if( cnt == n - 1)
                break;
        }
    }
    printf("%.2f", ans);
    return 0;
}
double calc_dist(int i, int j){
    return sqrt(pow((star[i].first - star[j].first), 2)
                + pow((star[i].second - star[j].second), 2));
}
bool compare(vector<double> a, vector<double> b){
    // v[0] = i, v[1] = j, v[2] = dist
    return a[2] < b[2];
}
int find(int i){
    if( parent[i] == -1 )
        return i;
    return find(parent[i]);
    
}
void Union(int x, int y){
    int xset = find(x);
    int yset = find(y);
    if( xset != yset )
        parent[xset] = yset;
}
bool isCycle(int src, int dest){
    int x = find(src);
    int y = find(dest);
    if ( x == y )//is Cycle
        return true;
    // isn't Cycle
    Union(x,y);
    return false;
}
