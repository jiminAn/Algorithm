#include <string>
#include <vector>
#include <math>
// 대각선은 2, 옆은 1

using namespace std;
string answer = "";


pair<int,int> left_hand(int l, int r);
pair<int,int> right_hand(int l, int r);

string solution(vector<int> num, string hand) {

    pair<int,int> memory_hand = make_pair(10, 12);// 10 == *, 12 == #
    pair<int,int> tmp;
    for(int i = 0; i < num.size(); i++){
        tmp = memory_hand;
        if( num[i] % 3 == 1 )// 키패드 상 왼쪽
            memory_hand = left_hand(num[i],tmp.second);

        else if( num[i]% 3 == 0 && num[i] != 0  )// 키패드 상 오른쪽
            memory_hand = right_hand(tmp.first,num[i]);

        else{ // 키패드 상 가운데 숫자를 누를 경우
            int temp = num[i];
            int dist_L, dist_R;
            
            if( num[i] == 0 )
                temp = 11;
            
            if(tmp.first % 3 == 1)
                dist_L = abs(temp - tmp.first - 1) / 3 + 1;
            else
                dist_L = abs(temp - tmp.first) / 3;

            if(tmp.second % 3 == 0)
                dist_R= abs(temp - tmp.second + 1) / 3 + 1;
            else
                dist_R = abs(temp - tmp.second) / 3;
            
            if( dist_L == dist_R ){// 두 손이 같은 거리일 경우
                if( hand == "right" )
                    memory_hand = right_hand(tmp.first,num[i]);
                else
                    memory_hand = left_hand(num[i],tmp.second);
            }
            else{// 두 손이 거리가 다를 경우
                if( dist_L > dist_R)// 오른쪽 손이 더 가까울 경우
                    memory_hand = right_hand(tmp.first,num[i]);
                else // 왼쪽 손이 더 가까울 경우
                    memory_hand = left_hand(num[i],tmp.second);
            }
        }
    }
    return answer;
}
pair<int,int> left_hand(int l, int r){
    answer += "L";
    return make_pair(l,r);

}
pair<int,int> right_hand(int l, int r){
    answer += "R";
    return make_pair(l,r);
}

