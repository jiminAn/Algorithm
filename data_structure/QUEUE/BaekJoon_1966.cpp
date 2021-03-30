#include <iostream>
#include <queue>
#include <list>

using namespace std;
queue<pair<int, int>> q; //리스트를 사용하는 queue 생성
priority_queue<int> pq; // 기본 컨테이너 vector<int>, 기본 정렬 기준 less(내림차순)
   
void init();
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int locate, len;
    int tmp_i, tmp_l;
    int ans;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> len >> locate;
        ans = 0;
        for(int j = 0; j < len; j++){
            cin >> tmp_i;
            q.push(make_pair(j,tmp_i));
            pq.push(tmp_i);
        }
        while(true){
            if( (tmp_i = q.front().second) < pq.top() ){
                tmp_l = q.front().first;
                q.pop();
                q.push(make_pair(tmp_l, tmp_i));
            }
            else if((tmp_i = q.front().second) == pq.top()){
                ans++;
                tmp_l = q.front().first;
                pq.pop();
                q.pop();
                if( tmp_l == locate )
                    break;
            }
    
        }
        cout << ans << '\n';
        init();
        
    }
}
void init(){
    while( !q.empty() )
           q.pop();

    while( !pq.empty() )
        pq.pop();

}


