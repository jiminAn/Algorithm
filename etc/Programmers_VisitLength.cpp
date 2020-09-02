#include <string>
#include <iostream>
using namespace std;
int solution(string dirs)
{
	int answer = 0;
    bool check[11][11][11][11] = {false};
    int dy[4] = {0,0,1,-1}; // R/L/U/D
    int dx[4] = {1,-1,0,0}; // R/L/U/D
    int x,y;
    int dir;
    int tmp_x, tmp_y;
    x = y = 5; //실제 좌표 상의 (0,0)-> 배열 index (5,5)
    for(int i = 0; i < dirs.length(); i++){
        if(dirs[i] == 'R') dir = 0;
        else if(dirs[i] == 'L') dir = 1;
        else if(dirs[i] == 'U') dir = 2;
        else dir = 3;
        
        tmp_x = x + dx[dir];
        tmp_y = y + dy[dir];
        
        if(tmp_x < 0 || tmp_x > 10 || tmp_y < 0 || tmp_y > 10)// 범위 체크
            continue;
        
        if(!check[x][y][tmp_x][tmp_y]){// 처음 방문한 길이라면
            answer++;
            check[x][y][tmp_x][tmp_y] = check[tmp_x][tmp_y][x][y] = true;
        }
        y = tmp_y;
        x = tmp_x;
    }
    return answer;
    
}
