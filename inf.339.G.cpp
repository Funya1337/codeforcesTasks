#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int findDiv(int n) {
	vector<int> divs;
	for (int i = 2; i < int(pow(n, 0.5)) + 2; i++) {
		if (n % i == 0) {
			divs.push_back(i);
			divs.push_back(n / i);
		}
	}
	set<int> s(divs.cbegin(), divs.cend());
	divs = vector<int>(s.cbegin(), s.cend());
	if (divs.size() == 0) return n;
	else {
		for (int i = 0; i < divs.size(); i++) {
			if (divs[i] != 1) return divs[i];
		}
	}
}

int main()
{
	int n;
	cin >> n;
	cout << findDiv(n) << endl;
}