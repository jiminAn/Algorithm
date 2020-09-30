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

int check_square(int start_row, int start_column);// 인덱스 별 가장 큰 정사각형 사이즈를 리턴해주는 함수

int main(void){
    string tmp;
    int temp;
    cin >> n >> m;
    // 예시 입력 받기
    for(int i = 0; i < n; i++){
        cin >> tmp;
        for(int j = 0; j < m; j++){
            rec[i][j] = tmp[j] - '0';
        }
    }
    // rect[0~n-2][0~m-2]를 모두 순회하여 
    // check_squre을 통해 각 인덱스 별 최대 정사각형 크기 구하기
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            temp = check_square(i, j);
            if( temp == 0 )// 정사각형이 안될 경우 패스 
                continue;
            else// 정사각형이 될 경우 squre 벡터에 임시 저장
                square.push_back(temp);
        }
    }
    // 정사각형이 되지 않는다면 디폴트로 1 반환
    if( square.size() == 0)
        cout << 1 << '\n';
    // 저장해둔 사이즈 중 가장 큰 정사각형 사이즈 반환
    else
        cout << *max_element(square.begin(), square.end()) <<'\n';
    return 0;
            
}

int check_square(int r,int c){
    int edge = rec[r][c];
    int size, len;
    int idx = 0;
    int ans = 0;
    // rec[r][c] 과 같은 꼭짓점을 찾아 column 벡터에 저장
    for(int j = c+1; j < m; j++)
        if( edge == rec[r][j] )
            column.push_back(j);
    size = column.size();

    // rec[r][c] 과 같은 꼭짓점 수만큼 반복
    while(size--){
        len = column[idx++] - c; //edge-꼭짓점 인덱스 차이 구하기
        // 최대 인덱스를 벗어날 경우 정사각형 체크를 하지 않음
        if( r + len >= n || c + len >= m )
            continue;
        // 정사각형을 찾을 경우
        if( edge == rec[r + len][c] && edge == rec[r + len][c + len] )
            if( ans < len + 1)// 이전에 찾은 정사각형 크기보다 크면 갱신
                ans = len + 1;
    }
    column.clear(); // column을 전역변수로 선언하였으므로 함수 종료시마다 clear해주기
    return ans*ans; // 정사각형의 너비를 리턴해주어야 함.
}

