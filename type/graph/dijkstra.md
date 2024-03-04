## ダイクストラ法
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = LLONG_MAX / 2;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> v(n, vector<pair<int, ll>>(0));
  /*辺の追加*/
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
  vector<ll> dist(n, inf);
  int top = /*始点*/;
  q.push(make_pair(0, top));
  dist[top] = 0;
  //探索
  while(!q.empty()){
    auto [c, f] = q.top(); q.pop();
    dist[f] = c;
    for (auto [a, b] : v[f]){
      if (dist[a] == inf){
        q.push(make_pair(b + c, a));
      }
    }
    while(!q.empty() && dist[q.top().second] != inf) q.pop();
  }
}
```
<a href = "https://github.com/tomo-224/klib/blob/main/type/graph.md">戻る</a>
