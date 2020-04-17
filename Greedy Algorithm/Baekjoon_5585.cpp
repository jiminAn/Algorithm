#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	vector<int> v = { 500,100,50,10,5,1};

	int money, change;
	int answer = 0;
	cin >> money;
	change = 1000 - money;

	for (int i = 0; i < v.size(); i++) {
		while (change - v[i] >= 0) {
			change -= v[i];
			answer++;
		}
		if (change == 0)
			break;
	}
	cout << answer;
}
