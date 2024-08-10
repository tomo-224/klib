# 辺のみ与えられたグラフから根付き木を作成

- 辺が繋がっている先を管理する二次元配列 `e`
- 根付き木の根 `top`

から、

- 頂点の親を管理する配列 `p`
- 頂点の子を管理する二次元配列 `c`
- 頂点の高さを管理する配列 `dist`

を生成します。

```cpp
#include <bits/stdc++.h>
using namespace std;

void makeTree(vector<vector<int>>& e, int top, vector<int>& p, vector<vector<int>>& c, vector<int>& dist) {
  int n = e.size();
  p = vector<int>(n, top);
  c = vector<vector<int>>(n, vector<int>(0));
  dist = vector<int>(n, -1);
  queue<int> q;
  q.push(top); dist[top] = 0;
  int f;
  while (!q.empty()) {
    f = q.front(); q.pop();
    for (int k : e[f]) {
      if (dist[k] != -1) continue;
      p[k] = f; c[f].emplace_back(k);
      dist[k] = dist[f] + 1;
      q.push(k);
    }
  }
  return;
}
```
