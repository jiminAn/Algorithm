#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n,m;
int rec[51][51];
vector<int> square;
vector<int> column;
vector<int> tmp_square;

int check_square(int start_row, int start_column);

int main(void){
    string tmp;
    int temp;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        for(int j = 0; j < m; j++){
            rec[i][j] = tmp[j] - '0';
        }
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            temp = check_square(i, j);
            if( temp == 0)
                continue;
            else
                square.push_back(temp);
        }
    }
    if( square.size() == 0)
        cout << 1 << '\n';
    else
        cout << *max_element(square.begin(), square.end()) <<'\n';
    return 0;
            
}
int check_square(int r,int c){
    int edge = rec[r][c];
    int size, len;
    int idx = 0;
    int ans = 0;
    for(int j = c+1; j < m; j++)
        if( edge == rec[r][j] )
            column.push_back(j);
    size = column.size();

    while(size--){
        len = column[idx++] - c;
        if( r + len >= n || c + len >= m )
            continue;
        if( edge == rec[r + len][c] && edge == rec[r + len][c + len] )
            if( ans < len + 1)
                ans = len + 1;
    }
    column.clear();
    return ans*ans;
}

