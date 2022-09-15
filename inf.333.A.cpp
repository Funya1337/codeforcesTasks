#include <iostream>
#include <string>

using namespace std;

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
	string res;
	for (int i = a; i <= b; i++) {
		if (i % 2 == 0)
			res += to_string(i) + " ";
	}
	cout << res << endl;
}