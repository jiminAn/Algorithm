#include <iostream>
#include <deque>


using namespace std;

string cmd[8] = {"push_front","push_back","pop_front","pop_back","size","empty","front","back"};
deque<int> dq;
int tmp;

int cmd_check(string t_cmd);
void cmd_execuate(int n);
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int cmd_n;
    cin >> n;
    string tmp_cmd;
    for(int i = 0; i < n; i++){
        cin >> tmp_cmd;
        cmd_n = cmd_check(tmp_cmd);
        if( cmd_n == 0 || cmd_n == 1)
            cin >> tmp;
        cmd_execuate(cmd_n);
    }
    
}
int cmd_check(string t_cmd){
    int i;
    for(i = 0; i < 8; i++)
        if(cmd[i].compare(t_cmd) == 0)
            break;
    return i;
}
void cmd_execuate(int n){
    int k;
    switch (n) {
        case 0:
            dq.push_front(tmp);
            break;
        case 1:
            dq.push_back(tmp);
            break;
        case 2:
            if( dq.empty() )
                cout << -1 << '\n';
            else{
                k = dq.front();
                dq.pop_front();
                cout << k << '\n';
            }
            break;
        case 3:
            if( dq.empty() )
                cout << -1 << '\n';
            else{
                k = dq.back();
                dq.pop_back();
                cout << k << '\n';
            }
            break;
        case 4:
            cout << dq.size() << '\n';
            break;
        case 5:
            cout << dq.empty() << '\n';
            break;
        case 6:
            if( dq.empty() )
                cout << -1 << '\n';
            else
                cout << dq.front() << '\n';
            break;
        case 7:
            if( dq.empty() )
                cout << -1 << '\n';
            else
                cout << dq.back() << '\n';
            break;
            
        default:
            break;
    }
}
