#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void printVector(vector<int> data)
{
  for (auto el: data)
    cout << el << " ";
  cout << endl;
}

void solution()
{
  int n;
  string s;
  cin >> n;
  cin >> s;
  int l = 0, r = n - 1, cnt = n;
  while (l < r)
  {
    if (s[l] != s[r])
      cnt -= 2;
    else
      break;
//    cout << cnt << endl;
//    cout << l << " " << r << endl;
    ++l;
    --r;
  }
  cout << cnt << endl;
}

void debug()
{
  solution();
}

void production()
{
  int t;
  cin >> t;
  while (t > 0)
  {
    solution();
    --t;
  }
}

int main()
{
//  debug();
  production();
}
