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

void print2dVector(vector<vector<int>> a)
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

vector<int> ans;

void findAns(vector<vector<int>> &dp, vector<int> &weights, int k, int s)
{
  if (dp[k][s] == 0)
    return;
  if (dp[k - 1][s] == dp[k][s])
    findAns(dp, weights, k - 1, s);
  else
  {
    findAns(dp, weights, k - 1, s - weights[k - 1]);
    ans.push_back(k);
  }
}

int main()
{
  int n, maxWeight;
  cin >> n >> maxWeight;

  vector<int> weights(n);
  vector<int> prices(n);

  for (int &i: weights)
    cin >> i;

  for (int &i: prices)
    cin >> i;

  int cnt = weights.size();

  vector<vector<int>> dp(cnt + 1, vector<int>(maxWeight + 1, 0));

  for (int k = 0; k <= cnt; ++k)
  {
    for (int s = 0; s <= maxWeight; ++s)
    {
      if (k == 0 || s == 0)
      {
        dp[k][s] = 0;
      }
      else
      {
        if (s >= weights[k - 1])
          dp[k][s] = max(dp[k - 1][s], dp[k - 1][s - weights[k - 1]] + prices[k - 1]);
        else
          dp[k][s] = dp[k - 1][s];
      }
    }
  }

  print2dVector(dp);
  findAns(dp, weights, cnt, maxWeight);
  cout << ans.size() << endl;
  printVector(ans);
}
