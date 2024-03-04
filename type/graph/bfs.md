## BFS(幅優先探索)
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = LLONG_MAX / 2;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(0));
  //辺の追加
  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b; a--; b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  vector<ll> dist(n, inf);
  queue<int> q;
  int top = /*start point here*/;
  q.push(top);
  dist[top] = 0;
  //幅優先探索
  while(!q.empty()){
    int f = q.front(); q.pop();
    for (int k : v[f]){
      if (dist[k] == inf){
        dist[k] = dist[f] + 1;
        q.push(k);
      }
    }
  }
}
```
<a href = "https://github.com/tomo-224/klib/blob/main/type/graph.md">戻る</a>
