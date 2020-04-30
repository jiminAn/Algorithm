#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	int tmp;
	cin >> n;
	vector<int> v1;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v1.push_back(tmp);
	}
	sort(v1.begin(), v1.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (binary_search(v1.begin(), v1.end(), tmp))
			cout << "1\n";
		else
			cout << "0\n";
	}
}