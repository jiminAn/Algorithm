#include <iostream>
#include <vector>

using namespace std;


int fibo_recursive(int n); // O(2^n)
int fibo_dp(int n); // O(n)


/* using power of the matrix
fn-1+ fn = | 0 1 |n-1  x |f0|
           | 1 1 |       |f1|
*/
int fibo_dnc(int n); // O(logn)
void multiply(int fibo[2][2], int m[2][2]);
void power(int fibo[2][2], int n);


int main(void){
    int ans;
    ans = fibo_recursive(20);
    cout << ans << '\n';
    ans = fibo_dp(6);
    cout << ans << '\n';
    ans = fibo_dnc(6);
    cout << ans << '\n';
    
    return 0;
}

int fibo_recursive(int n){
    if( n == 0)
        return 0;
    else if ( n == 1)
        return 1;
    else
        return fibo_recursive(n-1) + fibo_recursive(n-2);
    
}
\
int fibo_dp(int n){
    int  f[100];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= n; i++)
        f[i] = f[i-1] + f[i-2];
    return f[n];
}
int fibo_dnc(int n){
    int fibo[2][2] = {{1,1},{1,0}};
    if(n == 0)
        return 0;
    power(fibo, n-1);
    return fibo[0][0];
}
void power(int fibo[2][2], int n){
    if( n == 0 || n == 1)
        return;
    int m[2][2] = {{1,1},{1,0}};
    
    power(fibo, n/2);
    multiply(fibo, fibo);
    if( n % 2 != 0)
        multiply(fibo, m);
}
void multiply(int fibo[2][2], int m[2][2])
{
  int x =  fibo[0][0]*m[0][0] + fibo[0][1]*m[1][0];
  int y =  fibo[0][0]*m[0][1] + fibo[0][1]*m[1][1];
  int z =  fibo[1][0]*m[0][0] + fibo[1][1]*m[1][0];
  int w =  fibo[1][0]*m[0][1] + fibo[1][1]*m[1][1];
  
  fibo[0][0] = x;
  fibo[0][1] = y;
  fibo[1][0] = z;
  fibo[1][1] = w;
}
  
