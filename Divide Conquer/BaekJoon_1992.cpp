#include <iostream>
#include <string>
using namespace std;
int v[65][65]; // 1,1index부터 사용
void solution(int x, int y, int n);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	int s_tmp;
	for (int i = 1; i <= n; i++) {
		s_tmp = 0;
		cin >> s;
		for (int j = 1; j <= n; j++) {
			v[i][j] = s[s_tmp++] - '0';
		}
	}
	solution(1, 1, n);
	return 0;
}
void solution(int x, int y, int n) {
	int check = 0;
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (v[i][j] == 1)
				check++;
	if (check == 0) {//모두 흰색일 경우
		cout << 0;
		return;
	}
	else if (check == n * n) {//모두 검은색일 경우
		cout << 1;
		return;
	}
	cout << "(";
	solution(x, y, n / 2);
	solution(x, y + n / 2, n / 2);
	solution(x + n / 2, y, n / 2);
	solution(x + n / 2, y + n / 2, n / 2);
	cout << ")";
}
