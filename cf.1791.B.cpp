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
  int n, x = 0, y = 0;
  string s;
  cin >> n;
  cin >> s;
  for (const auto &el: s)
  {
    if (el == 'R')
      ++x;
    if (el == 'L')
      --x;
    if (el == 'U')
      ++y;
    if (el == 'D')
      --y;
    if (x == 1 && y == 1)
    {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
