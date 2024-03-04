## weighted(重み付き) Union-Find
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace data{
  struct w_dsu {
    vector<int> parent;
    vector<ll> weight;
    w_dsu(int n){
      parent = vector<int>(n, -1);
      weight = vector<ll>(n, 0);
    }
    int leader(int i){
      if (parent[i] < 0) return i;
      else {
        int ret = leader(parent[i]);
        weight[i] += weight[parent[i]];
        return parent[i] = ret;
      }
    }
    bool same(int a, int b){
      return (leader(a) == leader(b));
    }
    int size(int i){
      return -parent[leader(i)];
    }
    int merge(int a, int b, int w){
      int la = leader(a), lb = leader(b);
      if (la == lb) return (weight[a] - weight[b] == w ? la : -1);
      if (parent[la] >= parent[lb]){
        parent[lb] += parent[la];
        parent[la] = lb;
        weight[la] = weight[b] - weight[a] + w;
        return lb;
      }
      else {
        parent[la] += parent[lb];
        parent[lb] = la;
        weight[lb] = -(weight[b] - weight[a] + w);
        return la;
      }
    }
  };
}
int main(){
  int n, q; cin >> n >> q;
  data::w_dsu d(n);
  for (int i = 0; i < q; i++){
    int a, b; ll c; cin >> a >> b >> c;
    a--; b--;
    d.merge(a, b, c);
  }
}
```

<a href = "https://github.com/tomo-224/klib/blob/main/type/structure.md">戻る</a>
