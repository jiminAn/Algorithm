#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int c, n, tmp;
    int total;
    double avg;
    int scores[1000];
    double ans;
    int cnt;
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> n;
        total = 0;
        avg = 0.0;
        cnt = 0;
        for(int j = 0; j < n; j++){
            cin >> tmp;
            total += tmp;
            scores[j] = tmp;
        }
        avg = (float)total/n;
        for(int j = 0; j < n; j++){
            if( scores[j] > avg)
                cnt++;
        }
        ans = (double)cnt/n*100;
        cout.precision(3);
        cout << fixed << ans << '%' << '\n';
        
    } 
}
