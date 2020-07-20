#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main(void){
    queue<int, list<int>> q; //리스트를 사용하는 queue 생성
    int n;
    int tmp;
    int cnt = 0;
    cin >> n;
    
    for(int i = 0 ; i < n; i++)
        q.push(i+1);
    while(!q.empty()){
        if(cnt % 2 == 0){// 버리기
            tmp = q.front();
            q.pop();
        }
        else{// 맨 뒤로 넣기
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cnt++;
    }
    cout << tmp;
}



