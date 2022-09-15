#include <iostream>
#include <string>

using namespace std;

bool is_square(int n) {
	if (n < 1)
		return false;
	else {
		for (int i = 1; i < int(n / 2) + 2; i++) {
			if (i * i == n)
				return true;
		}
		return false;
	}
}

int main()
{
	//float a, b;
	//cin >> a;
	//cin >> b;
	//if (a == 0 && b != 0)
	//	cout << "NO";
	//else if (a == 0 && b == 0)
	//	cout << "INF";
	//else {
	//	float res = -b / a;
	//	if (res == (int)res) {
	//		cout << res;
	//	}
	//	else {
	//		cout << "NO";
	//	}
	//}

	int a, b;
	cin >> a;
	cin >> b;
	for (int i = a; i <= b; i++) {
		if (is_square(i))
			cout << i << endl;
	}
}