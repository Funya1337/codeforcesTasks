#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

void print(vector<int> const& a) {
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
}

vector<int> findDiv(int n) {
	vector<int> divs;
	for (int i = 1; i < int(pow(n, 0.5)) + 2; i++) {
		if (n % i == 0) {
			divs.push_back(i);
			divs.push_back(n / i);
		}
	}
	set<int> s(divs.cbegin(), divs.cend());
	divs = vector<int>(s.cbegin(), s.cend());
	return divs;
}

int main()
{
	int n;
	cin >> n;
	print(findDiv(n));
}