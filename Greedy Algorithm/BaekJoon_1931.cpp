#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> w;
	int n, s,f;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> f;
		w.push_back(make_pair(s, f));
	}
	sort(w.begin(), w.end(),compare);
	int tmp = w[0].second;
	int answer = 1;
	for (int i = 1; i < n; i++) {
		if (w[i].first >= tmp) {
			answer++;
			tmp = w[i].second;
		}
	}
	cout << answer << '\n';
}
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}
