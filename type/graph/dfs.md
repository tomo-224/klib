## DFS(深さ優先探索)
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> v;
vector<bool> seen;
int n;
void dfs(int arg){
  seen[arg] = true;
  for (int k : v[arg]){
    if (!seen[k]) dfs(k);
  }
  return;
}
int main(){
  int m;
  cin >> n >> m;
  //辺の追加
  v = vector<vector<int>>(n, vector<int>(0));
  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b; a--; b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  seen = vector<bool>(n, false);
  /*探索*/
}
```

<a href = "https://github.com/tomo-224/klib/blob/main/type/graph.md">戻る</a>
