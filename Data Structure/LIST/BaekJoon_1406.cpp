#include <iostream>
#include <list>
#include <string>

using namespace std;

list<char> lt;
list<char> ::iterator iter;
list<char> ::iterator iter2;

void printList();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    char cmd, tmp;
    string str;
    cin >> str;
    cin >> m;
    
    for(int i = 0; i < str.length(); i++)
        lt.push_back(str[i]);
    
    lt.push_back('E');// 문장 맨 뒤는 E로 표시 (커서)
    iter = lt.end(); //커서를 문장 맨 뒤에 위치
    iter--;
   
    for(int i = 0; i < m; i++){
        cin >> cmd;
        switch (cmd) {
            case 'L':// 커서를 왼쪽으로 한칸 옮김
                if( iter == lt.begin())// 커서가 문장의 맨 앞이면 무시
                    break;
                --iter;
                break;
            case 'D'://커서를 오른쪽으로 한칸 옮김
                if( *iter == 'E')// 커서가 문장의 맨 뒤면 무시
                    break;
                ++iter;
                break;
            case 'B':// 커서 왼쪽 문자 삭제
                if( iter == lt.begin())// 커서가 문장의 맨 앞이면 무시
                    break;
                --iter;//왼쪽으로 커서 이동
                iter = lt.erase(iter);//삭제
                break;
            case 'P':// 문자 왼쪽에 추가
                cin >> tmp;
                iter = lt.insert(iter, tmp);
                ++iter; // 커서 원위치
                break;
        }
    }
    printList();
}
void printList(){
    lt.pop_back();
    for(iter2 = lt.begin(); iter2 != lt.end(); ++iter2){
        cout << *iter2;
    }
    cout << '\n';
}

