//#include <iostream>
//using namespace std;
//void binary_confetti(int x, int y,int n);
//int v[129][129]; // 1,1index���� ���
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
//	if (tmp == 0) { //��� 0 �� ����� ��� 
//		white++;
//		return;
//	}
//	else if (tmp == n * n) { // ��� blue�� ��� ���̻������ tmp�� ����
//		blue++;
//		return;
//	}
//	binary_confetti(x, y, n / 2); // ���� ���
//	binary_confetti(x + n / 2, y, n / 2); // ���� �ϴ�
//	binary_confetti(x, y + n / 2, n / 2); // ���� ���
//	binary_confetti(x + n / 2, y + n / 2, n / 2); //���� �ϴ� 
//}


