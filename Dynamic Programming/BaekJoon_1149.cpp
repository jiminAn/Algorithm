#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
int rgb[3][1000] = {0, };

int solve();

int n;

int main(void){
    int ans;
    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%d %d %d", &rgb[0][i], &rgb[1][i], &rgb[2][i]);
    ans = solve();
    cout << ans;
}
int solve(){
    for(int i = 1; i < n; i++){
        //각각 현재를 r/g/b로 칠할 때
        rgb[0][i] += min({rgb[1][i-1],rgb[2][i-1]});
        rgb[1][i] += min({rgb[2][i-1],rgb[0][i-1]});
        rgb[2][i] += min({rgb[0][i-1],rgb[1][i-1]});
    }
    return min({rgb[0][n-1],rgb[1][n-1],rgb[2][n-1]});
}
