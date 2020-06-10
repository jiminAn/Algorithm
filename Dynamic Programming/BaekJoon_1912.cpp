#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int num[100010] = {};
    int dp[100010] = {};
    int max;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = 1; i <=n; i++){
        if(dp[i-1] > 0)
            dp[i] = dp[i-1] + num[i];
        else
            dp[i] = num[i];
    }
    //index 1~n (origin.0~n-1: dp,dp+n)
    max = *max_element(dp+1,dp+n+1);
    cout << max;
}
