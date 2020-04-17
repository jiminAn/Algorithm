#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int s, f; 
	int answer = 0;
	int n;
	cin >> n;

	vector <pair <int, int>> v;
	for (int i = 0; i < n; i++) {
		cin >> s >> f;
		v.push_back(make_pair(s, f));
	}
	sort(v.begin(), v.end(), compare);

	int min = v[0].second;
	answer++;

	for (int i = 1; i < n; i++) {
		if (v[i].first > min) {
			min = v[i].second;
			answer++;
		}
	}
	cout << answer;

	return 0;
}
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {//끝나는 시간이 같을 경우
		return a.first < b.first; //시작하는 시간 오름차순 정렬
	}
	return a.second < b.second; //끝나는 시간 오름차순 정렬
}