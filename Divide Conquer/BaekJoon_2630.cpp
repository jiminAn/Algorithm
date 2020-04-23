//#include <iostream>
//using namespace std;
//void binary_confetti(int x, int y,int n);
//int v[129][129]; // 1,1index부터 사용
//int blue, white; //white : 0 , blue : 1
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cin >> v[i][j];
//		}
//	}
//	
//	binary_confetti(1,1,n);
//	cout << white << "\n" << blue;
//
//	return 0;
//}
//void binary_confetti(int x, int y,int n) {
//	int tmp = 0;
//	for (int i = x; i < x + n; i++) {
//		for (int j = y; j < y + n; j++) {
//			if (v[i][j]) 
//				tmp++;
//		}
//	}
//	if (tmp == 0) { //모두 0 즉 흰색일 경우 
//		white++;
//		return;
//	}
//	else if (tmp == n * n) { // 모두 blue일 경우 종이사이즈와 tmp값 같음
//		blue++;
//		return;
//	}
//	binary_confetti(x, y, n / 2); // 좌측 상단
//	binary_confetti(x + n / 2, y, n / 2); // 촤측 하단
//	binary_confetti(x, y + n / 2, n / 2); // 우측 상단
//	binary_confetti(x + n / 2, y + n / 2, n / 2); //우측 하단 
//}


