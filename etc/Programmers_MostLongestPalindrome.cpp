#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(string s)
{
	int answer = 0;
	int check;
	int j, k;
	vector<int> v;
	if (s.length() <= 2)
		return 1;
	for (int i = 1; i < s.length(); i++) {
		check = 1;
		for (j = 1, k = 1; (i - j) >= 0 && (i + k) < s.length(); j++, k++) {
			if (s[i - j] == s[i + k])
				check += 2;
			else
				break;
		}
		if (check != 1)
			v.push_back(check);
		if (check == s.length())
			break;
	}
	answer = *max_element(v.begin(), v.end());
	return answer;
}