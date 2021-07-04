// 19537 전투시뮬레이션
#include <iostream>
#include <vector>
#include <queue>
#define f_MAXSIZE 501
#define k_MAXSIZE 10001

using namespace std;

struct unit{
    int power;
    int team;
    pair<int, int> pos;
};

const vector<int> dx = {0,-1,0,1};
const vector<int> dy = {-1,0,1,0};
vector<vector<int>> field(f_MAXSIZE, vector<int>(f_MAXSIZE,-1));
vector<int> rugged;
vector<unit> u(f_MAXSIZE*f_MAXSIZE/4);
vector<pair<int,pair<int,int>>> cmd(k_MAXSIZE);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, H, W;// 지형의 종류 수, 맵의 세로 길이, 맵의 가로 길이
    int M;// 유닛의 수
    int K; // 약진 명령 개수
    int r;
    
    cin >> N >> H >> W;
    
    // 지형 번호를 필드에 저장
    for(int i = 0 ; i < H; i++){
        for(int j = 0 ; j < W; j++){
            cin >> field[i][j];
        }
    }
    // 각 지형 번호의 험준도 저장
    for(int i = 0; i < N; i++){
        cin >> r;
        rugged.push_back(r);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> u[i].power;
        cin >> u[i].team;
        cin >> u[i].pos.first;
        cin >> u[i].pos.second;
        u[i].team += 1;
    }
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> cmd[i].first;
        cin >> cmd[i].second.first;
        cin >> cmd[i].second.second;
    }
    cout << "complete";
}

