
# 백준 단계별로 풀어보기
: 예제 출력에 대해 새롭게 알게 된 충격적인 사실...  
**각 케이스마다 한줄 씩~출력한다** 라고 써있으므로 '입력 다 받은 후 -> 출력' 으로 해도 되지만 각 케이스 마다 하나씩 출력해도 됨..이걸 지금 알앗뉴..

## 4단계 : while문 

### 10951번. A+B -4
- <https://www.acmicpc.net/problem/10951>  
: 두 정수를 입력받아 합을 출력하는 문제로 간단하나, 입력 받을 테스트케이스의 개수와 종료조건이 명시되어 있지 않다  
따라서 정상적인 프로그램 종료를 위해 데이터 소스로부터 더 이상 읽을 수 있는 데이터가 없음을 나타내야하는 문제가 발생한다  
이런 경우를 파일의 끝, EOF라고 하며, 프로그램에서 파일의 끝을 만났음을 알리기 위해 매크로로 정의된 EOF 값을 리턴한다 

**C++의 경우 아래와 같다** 

```
while( cin >> a >> b ){

  cout << a + b << '\n';
  
  }
```
이 경우, 입력받은 데이터 소스 a,b를 끝까지 읽어들인 이후에 a + b 값을 출력하게 된다

## 6단계: 1차원 배열

### 4344번. 평균은 넘겠지
- <https://www.acmicpc.net/problem/4344>  
: 반올림하여 소수점 셋째 짜리 출력 시 아래와 같은 코드 사용하기  
**precision()에는 반올림 내포**
```
ans = (double)cnt/n*100;
cout.precision(3);
cout << fixed; // 소수점 아래로 3번째까지 고정하여 씀
cout << ans << '%' << '\n'; // 소수점 아래로 세번째 수까지 출력
```
#### 추가 : 올림, 내림, 반올림은?  
- 헤더파일 <cmath>
  - 올림: ceil() // ceil(4.2) = 5.0
  - 내림: floor() // floor(4.2) = 4.0
  - 반올림: round() // round(4.6) = 5.0 , round(4.2) = 4.0
  

## 8단계: 문자열

### 1152번. 단어의 개수
- <https://www.acmicpc.net/problem/1152>  
: c++에서 공백 포함 문자열 읽기
```
#include <string>
int main(void){
    string str;
    getline(cin, str);
}
```

# 백준 분류별로 풀어보기

## 링크드리스트
### 1158번. 요세푸스 문제
- <https://www.acmicpc.net/problem/1158>  
: iterator 쓸 때 주의할 점  
it.erase(it) -> x : iterator에서 제거 연산을 사용할 경우 더 이상 해당 iterator를 사용하지 못함  
it = it.erase(it) -> o : 원소를 제거하고 다음 원소를 반환한 값을 it에 저장하여 삭제된 원소 다음의 원소를 iterator가 가리키게 함  
it = it.insert(it,2) 경우도 마찬가지, it는 삽입한 원소 2를 가리키게 된다. 

## 그리디 알고리즘
### 1541. 잃어버린 괄호
- <https://www.acmicpc.net/problem/1541>    
: 문자열로 받은 수학 수식을 c++에서 간편하게 계산하기 
```
#include <string>
strint str = "10+20-30+40";
string tmp = "";
int ans = 0;
bool minus_check = false;

for(int i = 0; i < str.length(); i++){
    if( str[i] == '+' || str[i] == '-' || str[i] == NULL ){
        if( minus_check ) //이전 부호가 마이너스일 경우 빼주기
            ans -= stoi(tmp);
        else //이전 부호가 플러스일 경우 더해주기
            ans += stoi(tmp);
        if( str[i] == '-' )
            minus_check = true;
        else
            minus_check = false;
        tmp = "":
        continue; //숫자만 tmp에 저장하기 위해
    }
    tmp += str[i];
}
```

# 프로그래머스 레벨별로 풀어보기
## LEVEL 2
### 방문길이
- <https://programmers.co.kr/learn/courses/30/lessons/49994>
: 좌표 문제 코드 간단히 꿀팁
1. x,y 이동 시 일일이 풀어써주는 것보다는 배열을 이용해서 코드를 짧게 만들어주는게 좋음 
```
int dy[4] = {0,0,1,-1}; // 오,왼,위,아
int dx[4] = {1,-1,0,0}; // 오,왼,위,아

if(dirs[i] == 'R') dir = 0;
else if(dirs[i] == 'L') dir = 1;
else if(dirs[i] == 'U') dir = 2;
else dir = 3;
        
x += dx[dir];
y += dy[dir];
```
2. x,y 가 이동할 수 있는 한계가 있을 경우 tmp_x, tmp_y를 이용하자
```
tmp_x = x + dx[dir];
tmp_y = y + dy[dir];

if(tmp_x < MIM_X || tmp_x > MAX_X || tmp_y < MIN_Y || tmp_y > MIN_Y)// 범위 체크
     break;
 // 범위안일 경우 이동좌표를 저장
 y = tmp_y;
 x = tmp_x;

```
