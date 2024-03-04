## クラスカル法
```cpp
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<ll, pair<int, int>>> v(m);
  //入力
  for (auto& [c, p] : v){
    auto& [a, b] = p;
    cin >> a >> b >> c;
    a--; b--;
  }
  //ソート
  sort(v.begin(), v.end());
  //クラスカル法
  dsu d(n);
  vector<vector<pair<int, ll>>> tree(n, vector<pair<int, ll>>(0));
  ll tree_size = 0;
  for (auto [c, p] : v){
    auto [a, b] = p;
    if (d.same(a, b)) continue;
    d.merge(a, b);
    tree[a].push_back(make_pair(b, c));
    tree[b].push_back(make_pair(a, c));
    tree_size += c;
  }
}
```

<a href =  "https://github.com/tomo-224/klib/blob/main/type/graph.md">戻る</a>
