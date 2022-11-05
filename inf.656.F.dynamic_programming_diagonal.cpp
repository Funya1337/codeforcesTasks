#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <stdio.h>
#include<tuple>
#include <cmath>
#include <typeinfo>
#include <map>
#define ll long long
#define INF 1e9
#define ull unsigned long long

using namespace std;

void printVector(vector<int> a)
{
  for (int &i: a)
    cout << i << " ";
  cout << endl;
}

void print2dVector(vector<vector<ull> > a)
{
  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < a[i].size(); j++)
    {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<ull>> dp(n, vector<ull>(m, 0));
  dp[0][0] = 1;

  for (int d = 0; d < 2 * max(n, m); ++d)
  {
    for (int j = 0; j <= d; ++j)
    {
      int i = d - j;
      if (i <= n - 1 && j <= m - 1)
      {
        if (dp[i][j] != 0)
        {
        if (i + 1 < n && j + 2 < m)
          dp[i + 1][j + 2] = dp[i][j] + dp[i + 1][j + 2];
        if (i + 2 < n && j + 1 < m)
          dp[i + 2][j + 1] = dp[i][j] + dp[i + 2][j + 1];
        if (i + 2 < n && j - 1 >= 0)
          dp[i + 2][j - 1] = dp[i][j] + dp[i + 2][j - 1];
        if (i - 1 >= 0 && j + 2 < m)
          dp[i - 1][j + 2] = dp[i][j] + dp[i - 1][j + 2];
        }
      }
    }
  }
  print2dVector(dp);
  cout << dp[n - 1][m - 1] << endl;
  return 0;
}
