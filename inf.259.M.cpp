#include <iostream>

using namespace std;

int main()
{
	int k;
	cin >> k;

	if (k == 1)
		cout << "YES";
	else {
		bool checker = false;
		for (int i = 2; i <= 9000; i++) {
			if ((4 * i - 4) == k) {
				checker = true;
				break;
			}
		}
		if (checker)
			cout << "YES";
		else
			cout << "NO";
	}
}