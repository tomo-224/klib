# 根付き木において二頂点の LCA を求める

## 概要
- 頂点の親を管理する配列 `p`
- 頂点の子を管理する二次元配列 `c` ( 任意 )
- 頂点の高さを管理する配列 `dist` ( 任意 )
- 根付き木の根 `root` ( 未設定の場合 0 )

から、任意の二頂点の LCA を求められるようにします。

## コンストラクタ
```cpp
tree_LCA tl(vector<int>& par, int r = 0)
tree_LCA tl(vector<int>& par, vector<vector<int>>& chi, int r = 0)
tree_LCA tl(vector<int>& par, vector<int>& dis, int r = 0)
```
- `par` → `p`
- `chi` → `c`
- `dis` → `dist`
- `r` → `root`

にそれぞれ対応しています。

## メンバ関数

### LCA
```cpp
// LCA
int lca(int a, int b)
```
- 二頂点 `a`, `b` の LCA を求めます。
### エラー出力
```cpp
// エラー出力
void err()
```
- 内部で持っているダブリングによるデータの中身をエラー出力します。

## ソースコード

```cpp
#include <bits/stdc++.h>
using namespace std;

class tree_LCA {

private:

  vector<vector<int>> d;
  vector<int> p, dist;
  vector<vector<int>> c;
  int root, size, d_size;
  
  void PtoC() {
    c = vector<vector<int>>(size, vector<int>(0));
    for (int i = 0; i < size; i++) if (p[i] != -1) c[p[i]].emplace_back(i);
  }
  
  void bfs() {
    dist = vector<int>(size, -1);
    queue<int> q;
    q.push(root); dist[root] = 0;
    int f;
    while (!q.empty()) {
      f = q.front(); q.pop();
      for (int k : c[f]) {
        dist[k] = dist[f] + 1;
        q.push(k);
      }
    }
    return;
  }
  
  void doubling() {
    d_size = (32 - __builtin_clz(unsigned(size)));
    d = vector<vector<int>>(d_size, vector<int>(size, -1));
    d[0] = p;
    for (int i = 0; i < d_size-1; i++) for (int j = 0; j < size; j++) d[i+1][j] = (d[i][j] == -1 ? -1 : d[i][d[i][j]]);
  }

public:

  tree_LCA(vector<int>& par, int r = 0) : p(par), root(r), size(p.size()) {
    PtoC(); bfs(); doubling();
  }
  
  tree_LCA(vector<int>& par, vector<vector<int>>& chi, int r = 0) : p(par), c(chi), root(r), size(p.size()) {
    bfs(); doubling();
  }
  
  tree_LCA(vector<int>& par, vector<int>& dis, int r = 0) : p(par), dist(dis), root(r), size(p.size()) {
    doubling();
  }
  
  void err() {
    for (int i = 0; i < d_size; i++) {
      for (int j = 0; j < size; j++) cerr << d[i][j] << ' ';
      cerr << '\n';
    }
    cerr << flush;
    return;
  }
  
  int lca(int a, int b) {
    if (dist[a] < dist[b]) swap(a, b);
    unsigned dif = dist[a] - dist[b];
    for (int i = 0; i < 32; i++) if (dif & (1u << i)) a = d[i][a];
    if (a == b) return a;
    for (int i = d_size; i--;) if (d[i][a] != d[i][b]) a = d[i][a], b = d[i][b];
    return p[a];
  }
  
};
```

<a href = "https://github.com/tomo-224/klib/blob/main/type/graph.md">戻る</a>
