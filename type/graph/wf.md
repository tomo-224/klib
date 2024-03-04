
## ワーシャル・フロイド法
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = LLONG_MAX / 2;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(n, inf));
  //入力
  for (int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c; a--; b--;
    v[a][b] = c;
  }
  //初期化
  for (int i = 0; i < n; i++){
    v[i][i] = 0;
  }
  //ワーシャル・フロイド法
  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
      }
    }
  }
}
```

<a href =  "https://github.com/tomo-224/klib/blob/main/type/graph.md">戻る</a>
