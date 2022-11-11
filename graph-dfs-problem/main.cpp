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

void graphRoutes(map<int, vector<int>> a)
{
  for (auto const &kv : a)
  {
    std::cout << kv.first << " =>";
    for (auto const &i : kv.second)
        std::cout << " " << i;
    std::cout << std::endl;
  }
}

void graphIsVisited(map<int, vector<bool>> a)
{
  for (auto const &kv : a)
  {
    std::cout << kv.first << " =>";
    for (auto const &i : kv.second)
        std::cout << " " << i;
    std::cout << std::endl;
  }
}

map<int, vector<int>> graph;
map<int, vector<bool>> isVisited;

void dfs(int x, vector<int> into)
{
  for (int i = 0; i < into.size(); ++i)
  {
    bool checker = false;
    for (int j = 0; j < graph[into[i]].size(); ++j)
    {
      if (graph[into[i]][j] == x)
        isVisited[into[i]][j] = 1;
    }
    for (int j = 0; j < isVisited[into[i]].size(); ++j)
    {
      if (isVisited[into[i]][j] == 0)
        checker = true;
    }

    if (checker)
    {
      graphIsVisited(isVisited);
//      cout << into[i] << endl;
//      cout << "???????????????" << endl;
//      printVector(graph[into[i]]);
      dfs(into[i], graph[into[i]]);
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  int res = 0;
  if (m == 0)
    cout << n << endl;
  else
  {
    for (int i = 0; i < m; ++i)
    {
      int s, e;
      cin >> s >> e;

      graph.insert(pair<int, vector<int>>(s, vector<int>()));
      graph[s].push_back(e);
      graph.insert(pair<int, vector<int>>(e, vector<int>()));
      graph[e].push_back(s);

      isVisited.insert(pair<int, vector<bool>>(s, vector<bool>()));
      isVisited[s].push_back(false);
      isVisited.insert(pair<int, vector<bool>>(e, vector<bool>()));
      isVisited[e].push_back(false);
    }
  }
  dfs(graph.begin()->first, graph[graph.begin()->first]);
//  graphRoutes(graph);
//  cout << "-------------" << endl;
//  graphIsVisited(isVisited);
}
