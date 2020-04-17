#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int NucleoCheck(char n);
char transferNucleo(int n);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<string> v;
	char* answer;
	int hammingDistance = 0;
	vector<int> check(4); //ACGT
	int maxIndex, maxElement;
	int nuclo;
	int row, column;
	string tmp;
	cin >> column >> row;
	answer = new char[row];

	for (int i = 0; i < column; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < row; i++) {
		check[0] = 0, check[1] = 0, check[2] = 0, check[3] = 0;
		for (int j = 0; j < column; j++) {
			nuclo = NucleoCheck(v[j][i]);
			check[nuclo]++;

		}
		maxIndex = max_element(check.begin(), check.end()) - check.begin();
		maxElement = *max_element(check.begin(), check.end());
		hammingDistance += column - maxElement;
		answer[i] = transferNucleo(maxIndex);
		
	}
	for (int i = 0; i < row; i++)
		cout << answer[i];
	cout << '\n';
	cout << hammingDistance;

	return 0;
}
int NucleoCheck(char n) {
	if (n == 'A')
		return 0;
	else if (n == 'C')
		return 1;
	else if (n == 'G')
		return 2;
	else
		return 3;
}
char transferNucleo(int n) {
	if (n == 0)
		return 'A';
	else if (n == 1)
		return 'C';
	else if (n == 2)
		return 'G';
	else
		return 'T';
}
