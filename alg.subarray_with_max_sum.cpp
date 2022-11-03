#include <iostream>

using namespace std;

int findMaxSum(vector<int> a, int n)
{
  int ans = a[0],
    ans_l = 0,
    ans_r = 0,
    sum = 0,
    min_sum = 0,
    min_pos = -1;
  for (int r = 0; r < n; ++r) {
    sum += a[r];

    int cur = sum - min_sum;
    if (cur > ans) {
      ans = cur;
      ans_l = min_pos + 1;
      ans_r = r;
    }

    if (sum < min_sum) {
      min_sum = sum;
      min_pos = r;
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<tuple<int, int> > minPosSumVect;
  for (int &i: a)
    cin >> i;

  int maxSum = findMaxSum(a, a.size());
  int maxEl1 = -INF;
  int minEl1 = INF;
  int idx1, idx2;
  int ans = a[0],
    ans_l = 0,
    ans_r = 0,
    sum = 0,
    min_sum = 0,
    min_pos = -1;

  minPosSumVect.push_back(tuple<int, int>(min_pos, min_sum));
  vector<int> vectL;
  vector<int> vectR;

  for (int r = 0; r < n; ++r) {
    sum += a[r];

    int cur = sum - min_sum;
    if (cur == maxSum) {
      ans = cur;
      ans_l = min_pos + 1;
      ans_r = r;
      for (int i = 0; i < minPosSumVect.size(); ++i)
      {
        if (get<1>(minPosSumVect[i]) == min_sum)
        {
          vectL.push_back(get<0>(minPosSumVect[i]));
          vectR.push_back(ans_r);
        }
      }
    }

    if (sum <= min_sum) {
      min_sum = sum;
      min_pos = r;
      minPosSumVect.push_back(tuple<int, int>(min_pos, min_sum));
    }
  }

  if (equal(vectR.begin() + 1, vectR.end(), vectR.begin()))
  {
    for (int i = 0; i < vectL.size(); ++i)
    {
      if (maxEl1 <= vectL[i])
      {
        maxEl1 = vectL[i];
        idx1 = i;
      }
    }
    cout << vectL[idx1] + 2 << endl;
    cout << vectR[0] + 1 << endl;
  }
  else
  {
    for (int i = 0; i < vectR.size(); ++i)
    {
      if (minEl1 >= vectR[i])
      {
        minEl1 = vectR[i];
        idx2 = i;
      }
    }
    cout << vectL[idx2] + 2 << endl;
    cout << vectR[idx2] + 1 << endl;
  }
}
