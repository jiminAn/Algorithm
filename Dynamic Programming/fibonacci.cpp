#include <iostream>
#include <vector>

using namespace std;

vector<int> memo(100);
int recursive_fibo(int n);
int memo_fibo(int n);
void memo_init(int n);



int main(void){
    int ans = recursive_fibo(20);
    cout << ans << '\n';
    
    memo_init(20);
    ans = memo_fibo(20);
    cout << ans << '\n';
    
    return 0;
}

int recursive_fibo(int n){
    if( n == 0)
        return 0;
    else if ( n == 1)
        return 1;
    else
        return recursive_fibo(n-1) + recursive_fibo(n-2);
    
}
void memo_init(int n){
    for(int i = 0; i <= n; i++)
        memo[i] = 0;
    memo[1] = 1;
}
int memo_fibo(int n){
    if(n >= 2 && memo[n] == 0)
        memo[n] = memo_fibo(n-1) + memo_fibo(n-2);
    return memo[n];
}
