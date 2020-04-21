#include <string>
#include <iostream>
using namespace std;
int solution(string dirs)
{
	int answer = 0;
    bool check[11][11][11][11] = {false};
    int x,y;
    x = y = 5; //실제 좌표 상의 (0,0) -> 배열 index (5,5)
    
    /*(x1,y1)->(x2,y2)로 이동할 경우 지나간 길 경로 체크시 방향성이 없는 문제이므로
    (x2,y2)->(x1,y1)도 체크해주어야 함*/
    for(int i = 0; i < dirs.length(); i++){
        if(dirs[i] == 'U'){
            if( y < 10){ //y가 9일때가 up할 수 있는 최대치
                if(check[x][y][x][y+1] == false){
                    check[x][y][x][y+1] = true;
                    check[x][y+1][x][y] = true;
                    answer++;
                }
                y++;
            }
        }
        if(dirs[i] == 'D'){
            if( y  > 0){ //y가 1일 때가 down할 수 있는 최소치
                if(check[x][y][x][y-1] == false){
                    check[x][y][x][y-1] = true;
                    check[x][y-1][x][y] = true;
                    answer++;
                }
                y--;
            }
        }
        if(dirs[i] == 'R'){
            if( x < 10){ //x가 9일때가 right할 수 있는 최대치
                if(check[x][y][x+1][y] == false){
                    check[x][y][x+1][y] = true;
                    check[x+1][y][x][y] = true;
                    answer++;
                }
                x++;
            }
        }
        if(dirs[i] == 'L'){
            if( x > 0){ //x가 1일때가 left할 수 있는 최대치
                if(check[x][y][x-1][y] == false){
                    check[x][y][x-1][y] = true;
                    check[x-1][y][x][y] = true;
                    answer++;
                }
                x--;
            }
        }
    }
    return answer;
    
}
