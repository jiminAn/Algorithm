#include <iostream>
#include <list>
using namespace std;
list<int> lt;
list<int>::iterator iter = lt.begin();

void printList();
int main(void){
    int n,k;
    int cnt = 0;
    int idx = 0;
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++)
        lt.push_back(i);
    
    iter = lt.begin();
    cout << '<';
    while(!lt.empty()){
        if( ++cnt == k){
            cnt = 0;
            if( ++idx != n)
                cout << *iter <<", ";
            else
                cout << *iter << '>';
            iter = lt.erase(iter);
            if( iter == lt.end())
                iter = lt.begin();
            continue;
    
        }
        if( ++iter == lt.end() ){
            iter = lt.begin();
           
        }
    }

}


