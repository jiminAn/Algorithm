#include <string>
#include <vector>
#include <iostream>
// 대각선은 2, 옆은 1

using namespace std;
string answer = "";
int dist[10][12] = {
    {0,4,3,4,3,2,3,2,1,2,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {3,1,0,1,2,1,2,3,2,3,4,4},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,1,2,1,0,1,2,1,2,3,3},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {1,3,2,3,2,1,2,1,0,1,2,2},
    {0,0,0,0,0,0,0,0,0,0,0,0}
};

pair<int,int> left_hand(int l, int r);
pair<int,int> right_hand(int l, int r);


int main(void){
    vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    string hand = "right";

    
    pair<int,int> memory_hand = make_pair(10, 11);// 10 == *, 11 == #
    pair<int,int> tmp;
    
    for(int i = 0; i < num.size(); i++){
        tmp = memory_hand;
        if( num[i] % 3 == 1)// 키패드 상 왼쪽
            memory_hand = left_hand(num[i],tmp.second);

        else if( num[i] % 3 == 0 && num[i] != 0 )// 키패드 상 오른쪽
            memory_hand = right_hand(tmp.first,num[i]);

        else{ // 키패드 상 가운데 숫자를 누를 경우
            if( dist[num[i]][tmp.first] == dist[num[i]][tmp.second] ){// 두 손이 같은 거리일 경우
                if( hand == "right" )
                    memory_hand = right_hand(tmp.first,num[i]);
                else
                    memory_hand = left_hand(num[i],tmp.second);
            }
            else{// 두 손이 거리가 다를 경우
                cout << "memory" << tmp.first << tmp.second << '\n';
                cout << num[i] << ':' << dist[num[i]][tmp.first] << dist[num[i]][tmp.second] << '\n';
                if( dist[num[i]][tmp.first] > dist[num[i]][tmp.second])// 오른쪽 손이 더 가까울 경우
                    memory_hand = right_hand(tmp.first,num[i]);
                else // 왼쪽 손이 더 가까울 경우
                    memory_hand = left_hand(num[i],tmp.second);
         
            }
        }
    }
    cout << answer;
    return 1;
}

pair<int,int> left_hand(int l, int r){
    answer += "L";
    return make_pair(l,r);
        
}
pair<int,int> right_hand(int l, int r){
    answer += "R";
    return make_pair(l,r);
}
