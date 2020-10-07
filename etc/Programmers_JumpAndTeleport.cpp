#include <iostream>

using namespace std;

int solution(int n){
    int tmp, ans;
    ans = 1;// 순간이동을 하기 위해서는 최초 1칸은 이동
        
    while( n != 1){
         tmp = 0;
        // 입력받은 길이가 홀수 일 경우 teleport후 jump 1번을 더 해줘야 하므로 비용 1 증가
        if( n % 2 != 0){
            n -= 1;
            tmp = 1;
        }
        // 입력받은 길이가 짝수 일 경우 (길이/2)지점에서 텔레포트
        else
            n /= 2;
        // 비용이 들었을 경우 ans + 1
        if( tmp ) 
            ans += tmp;
    }
    return ans;
}
