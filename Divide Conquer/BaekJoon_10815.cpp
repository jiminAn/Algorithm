#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void showVector(vector<int> v);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	int tmp;
	vector<int> v1;
	vector<int> v2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v1.push_back(tmp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		v2.push_back(tmp);
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < v2.size(); i++) {
		if ( binary_search(v1.begin(),v1.end(),v2[i]) )
			v2[i] = 1;
		else
			v2[i] = 0;
	}
	showVector(v2);
}
void showVector(vector<int> v) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << '\n';
}