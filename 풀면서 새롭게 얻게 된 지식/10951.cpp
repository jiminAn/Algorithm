#include <iostream>

using namespace std;

int main(void){
    int A,B;
    
    int sum_arr[100];
    for(int i = 0; i < 5; i++){
        cin >> A >> B;
        sum_arr[i] = A + B;
    }
    for(int i = 0; i < 5; i++)
        cout << sum_arr[i] << '\n';
}
