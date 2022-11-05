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

//ull factorial(int N)
//{
//    ull f = 1;
//    for (ull i = 2; i <= N; i++)
//        f *= i;
//
//    return f;
//}
//
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

//
//vector<int> recheto()
//{
//  int n = 100;
//  vector<int> a(100, 1);
//  for (int i = 2; i * i <= n; ++i)
//  {
//    if (a[i] == 1)
//    {
//      for (int j = i * i; j <= n; j += i)
//      {
//        a[j] = 0;
//      }
//    }
//  }
//  return a;
//}
//
//ll upperBound(vector<ll> data, ll el)
//{
//  ll l = -1;
//  ll r = data.size();
//  while (l + 1 < r)
//  {
//    ll mid = (l + r) / 2;
//    if (data[mid] >= el)
//      r = mid;
//    else
//      l = mid;
//  }
//  return r;
//}
//
//ll lowerBound(vector<ll> data, ll el)
//{
//  ll l = -1;
//  ll r = data.size();
//  while (l + 1 < r)
//  {
//    ll mid = (l + r) / 2;
//    if (data[mid] > el)
//      r = mid;
//    else
//      l = mid;
//  }
//  return l;
//}
//
//ll findClose(vector<ll> &data, ll el)
//{
//  ll l = -1;
//  ll r = data.size();
//  while (l + 1 < r)
//  {
//    ll mid = (l + r) / 2;
//    if (data[mid] > el)
//      r = mid;
//    else if (data[mid] < el)
//      l = mid;
//    else
//      return el;
//  }
//  ll diff1 = abs(el - data.at(l));
//  ll diff2 = abs(el - data.at(r));
//  if (diff1 == diff2)
//    return min(data[l], data[r]);
//  else
//    return diff1 < diff2 ? data[l] : data[r];
//}
//
//vector<int> ans;
//vector<int> data;
//
//void rec(int idx, int sum)
//{
//  cout << idx << " " << sum << endl;
//  if (idx == data.size() - 1)
//  {
//    ans.push_back(sum);
//    return;
//  }
//  if (idx + 1 <= data.size() - 1)
//    rec(idx + 1, sum + data[idx + 1]);
//  if (idx + 2 <= data.size() - 1)
//    rec(idx + 2, sum + data[idx + 2]);
//}

class BigInt{
    string digits;
public:

    //Constructors:
    BigInt(unsigned long long n = 0);
    BigInt(string &);
    BigInt(const char *);
    BigInt(BigInt &);

    //Helper Functions:
    friend void divide_by_2(BigInt &a);
    friend bool Null(const BigInt &);
    friend int Length(const BigInt &);
    int operator[](const int)const;

               /* * * * Operator Overloading * * * */

    //Direct assignment
    BigInt &operator=(const BigInt &);

    //Post/Pre - Incrementation
    BigInt &operator++();
    BigInt operator++(int temp);
    BigInt &operator--();
    BigInt operator--(int temp);

    //Addition and Subtraction
    friend BigInt &operator+=(BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt &operator-=(BigInt &, const BigInt &);

    //Comparison operators
    friend bool operator==(const BigInt &, const BigInt &);
    friend bool operator!=(const BigInt &, const BigInt &);

    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);

    //Multiplication and Division
    friend BigInt &operator*=(BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
    friend BigInt &operator/=(BigInt &, const BigInt &);
    friend BigInt operator/(const BigInt &, const BigInt &);

    //Modulo
    friend BigInt operator%(const BigInt &, const BigInt &);
    friend BigInt &operator%=(BigInt &, const BigInt &);

    //Power Function
    friend BigInt &operator^=(BigInt &,const BigInt &);
    friend BigInt operator^(BigInt &, const BigInt &);

    //Square Root Function
    friend BigInt sqrt(BigInt &a);

    //Read and Write
    friend ostream &operator<<(ostream &,const BigInt &);
    friend istream &operator>>(istream &, BigInt &);

    //Others
    friend BigInt NthCatalan(int n);
    friend BigInt NthFibonacci(int n);
    friend BigInt Factorial(int n);
};

BigInt::BigInt(string & s){
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(unsigned long long nr){
    do{
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}
BigInt::BigInt(const char *s){
    digits = "";
    for (int i = strlen(s) - 1; i >= 0;i--)
    {
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(BigInt & a){
    digits = a.digits;
}

bool Null(const BigInt& a){
    if(a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}
int Length(const BigInt & a){
    return a.digits.size();
}
int BigInt::operator[](const int index)const{
    if(digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}
bool operator==(const BigInt &a, const BigInt &b){
    return a.digits == b.digits;
}
bool operator!=(const BigInt & a,const BigInt &b){
    return !(a == b);
}
bool operator<(const BigInt&a,const BigInt&b){
    int n = Length(a), m = Length(b);
    if(n != m)
        return n < m;
    while(n--)
        if(a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}
bool operator>(const BigInt&a,const BigInt&b){
    return b < a;
}
bool operator>=(const BigInt&a,const BigInt&b){
    return !(a < b);
}
bool operator<=(const BigInt&a,const BigInt&b){
    return !(a > b);
}

BigInt &BigInt::operator=(const BigInt &a){
    digits = a.digits;
    return *this;
}

BigInt &BigInt::operator++(){
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9;i++)
        digits[i] = 0;
    if(i == n)
        digits.push_back(1);
    else
        digits[i]++;
    return *this;
}
BigInt BigInt::operator++(int temp){
    BigInt aux;
    aux = *this;
    ++(*this);
    return aux;
}

BigInt &BigInt::operator--(){
    if(digits[0] == 0 && digits.size() == 1)
        throw("UNDERFLOW");
    int i, n = digits.size();
    for (i = 0; digits[i] == 0 && i < n;i++)
        digits[i] = 9;
    digits[i]--;
    if(n > 1 && digits[n - 1] == 0)
        digits.pop_back();
    return *this;
}
BigInt BigInt::operator--(int temp){
    BigInt aux;
    aux = *this;
    --(*this);
    return aux;
}

BigInt &operator+=(BigInt &a,const BigInt& b){
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if(m > n)
        a.digits.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n;i++){
        if(i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if(t)
        a.digits.push_back(t);
    return a;
}
BigInt operator+(const BigInt &a, const BigInt &b){
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}

BigInt &operator-=(BigInt&a,const BigInt &b){
    if(a < b)
        throw("UNDERFLOW");
    int n = Length(a), m = Length(b);
    int i, t = 0, s;
    for (i = 0; i < n;i++){
        if(i < m)
            s = a.digits[i] - b.digits[i]+ t;
        else
            s = a.digits[i]+ t;
        if(s < 0)
            s += 10,
            t = -1;
        else
            t = 0;
        a.digits[i] = s;
    }
    while(n > 1 && a.digits[n - 1] == 0)
        a.digits.pop_back(),
        n--;
    return a;
}
BigInt operator-(const BigInt& a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}

BigInt &operator*=(BigInt &a, const BigInt &b)
{
    if(Null(a) || Null(b)){
        a = BigInt();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            v[i + j] += (a.digits[i] ) * (b.digits[j]);
        }
    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i] ;
    }
    for (int i = n - 1; i >= 1 && !v[i];i--)
            a.digits.pop_back();
    return a;
}
BigInt operator*(const BigInt&a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}

BigInt &operator/=(BigInt& a,const BigInt &b){
    if(Null(b))
        throw("Arithmetic Error: Division By 0");
    if(a < b){
        a = BigInt();
        return a;
    }
    if(a == b){
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i]  < b;i--){
        t *= 10;
        t += a.digits[i] ;
    }
    for (; i >= 0; i--){
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t;cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a.digits.resize(cat.size());
    for (i = 0; i < lgcat;i++)
        a.digits[i] = cat[lgcat - i - 1];
    a.digits.resize(lgcat);
    return a;
}
BigInt operator/(const BigInt &a,const BigInt &b){
    BigInt temp;
    temp = a;
    temp /= b;
    return temp;
}

BigInt &operator%=(BigInt& a,const BigInt &b){
    if(Null(b))
        throw("Arithmetic Error: Division By 0");
    if(a < b){
        a = BigInt();
        return a;
    }
    if(a == b){
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b;i--){
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--){
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t;cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a = t;
    return a;
}
BigInt operator%(const BigInt &a,BigInt &b){
    BigInt temp;
    temp = a;
    temp %= b;
    return temp;
}

BigInt &operator^=(BigInt & a,const BigInt & b){
    BigInt Exponent, Base(a);
    Exponent = b;
    a = 1;
    while(!Null(Exponent)){
        if(Exponent[0] & 1)
            a *= Base;
        Base *= Base;
        divide_by_2(Exponent);
    }
    return a;
}
BigInt operator^(BigInt & a,BigInt & b){
    BigInt temp(a);
    temp ^= b;
    return temp;
}

void divide_by_2(BigInt & a){
    int add = 0;
    for (int i = a.digits.size() - 1; i >= 0;i--){
        int digit = (a.digits[i] >> 1) + add;
        add = ((a.digits[i] & 1) * 5);
        a.digits[i] = digit;
    }
    while(a.digits.size() > 1 && !a.digits.back())
        a.digits.pop_back();
}

BigInt sqrt(BigInt & a){
    BigInt left(1), right(a), v(1), mid, prod;
    divide_by_2(right);
    while(left <= right){
        mid += left;
        mid += right;
        divide_by_2(mid);
        prod = (mid * mid);
        if(prod <= a){
            v = mid;
            ++mid;
            left = mid;
        }
        else{
            --mid;
            right = mid;
        }
        mid = BigInt();
    }
    return v;
}

BigInt NthCatalan(int n){
    BigInt a(1),b;
    for (int i = 2; i <= n;i++)
        a *= i;
    b = a;
    for (int i = n + 1; i <= 2 * n;i++)
        b *= i;
    a *= a;
    a *= (n + 1);
    b /= a;
    return b;
}

BigInt NthFibonacci(int n){
    BigInt a(1), b(1), c;
    if(!n)
        return c;
    n--;
    while(n--){
        c = a + b;
        b = a;
        a = c;
    }
    return b;
}

BigInt Factorial(int n){
    BigInt f(1);
    for (int i = 2; i <= n;i++)
        f *= i;
    return f;
}

istream &operator>>(istream &in,BigInt&a){
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}

ostream &operator<<(ostream &out,const BigInt &a){
    for (int i = a.digits.size() - 1; i >= 0;i--)
        cout << (short)a.digits[i];
    return cout;
}

bool checkInput(string s, string alf)
{
  bool c1 = false;
  bool c2 = false;
  if (alf.find(s[0]) != string::npos && alf.find(s[3]) != string::npos)
    c1 = true;
  int num1 = int(s[1] - '0');
  int num2 = int(s[4] - '0');
  if (1 <= num1 <= 8 && 1 <= num2 <= 8)
    c2 = true;
  if (c1 && c2 && s[2] == '-')
    return true;
  return false;
}

vector<vector<char> > input2dVector(int n, int m, char t)
{
  vector<vector<char> > a1(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a1[i].resize(m);
      cin >> t;
      a1[i][j] = t;
    }
  }
  return a1;
}

//int n = 5;
//vector<int> a(n);
//vector<int> index(n);
//vector<int> data{ 0, 1 };
//
//void rec(int idx)
//{
//  if (idx == n)
//  {
//    for (int i = 0; i < a.size() - 1; ++i)
//    {
//      cout << i << " " << i + 1 << endl;
//    }
//    printVector(a);
//    return;
//  }
//  for (int i = 0; i < data.size(); ++i)
//  {
//    a[idx] = data[i];
//    rec(idx + 1);
//  }
//}

bool checkNumber(ull n)
{
  string strNum = to_string(n);
  vector<ull> vect;
  for (int i = 0; i < strNum.size(); ++i)
  {
    int el = int(strNum[i] - '0');
    vect.push_back(el);
  }
  return is_sorted(vect.begin(), vect.end());
}

//void mult(vector<vector<ull> > a, ull power, ull m)
//{
//  ull n = matrix.size();
//  vector<vector<ull> > res(n);
//  for (ull i = 0; i < n; ++i) {
//    res[i].resize(n);
//  }
//  for (ull k = 0; k < n; ++k)
//  {
//    for (ull i = 0; i < n; ++i)
//    {
//      ull sum = 0;
//      for (ull j = 0; j < n; ++j)
//      {
//        sum += matrix[j][i] * res[k][j];
//      }
//      res[k][i] = sum % m;
//    }
//  }
//  print2dVector(res);
//}

vector<vector<ull>> multMatrix(vector<vector<ull>> &a, vector<vector<ull>> b, ull m)
{
  ull n = a.size();
  vector<vector<ull> > c(n);
  for (ull i = 0; i < n; ++i) {
    c[i].resize(n);
  }
  for (ull k = 0; k < n; ++k)
  {
    for (ull i = 0; i < n; ++i)
    {
      ull sum = 0;
      for (ull j = 0; j < n; ++j)
      {
        sum += a[j][i] * b[k][j];
      }
      c[k][i] = sum % m;
    }
  }
  return c;
}

vector<vector<ull>> modExp(vector<vector<ull>> &a, ull b, ull c, vector<vector<ull>> &i_matrix)
{
  if (b == 0) return i_matrix;
  if (b % 2 == 1)
    return multMatrix(a, modExp(a, b - 1, c, i_matrix), c);
  vector<vector<ull>> d = modExp(a, b / 2, c, i_matrix);
  return multMatrix(d, d, c);
}

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
