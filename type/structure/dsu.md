## dsu(Union-Find、素集合データ構造)

```cpp
#include <bits/stdc++.h>
using namespace std;
namespace structure {
  struct dsu {
    vector<int> parent;
    dsu(int n){
      parent = vector<int>(n, -1);
    }
    int leader(int i){
      if (parent[i] < 0) return i;
      else return parent[i] = leader(parent[i]);
    }
    bool same(int a, int b){
      return (leader(a) == leader(b));
    }
    int size(int i){
      return -parent[leader(i)];
    }
    int merge(int a, int b){
      int la = leader(a), lb = leader(b);
      if (la == lb) return la;
      if (size(la) > size(lb)){
        parent[lb] += parent[la];
        parent[la] = lb;
        return lb;
      }
      else {
        parent[la] += parent[lb];
        parent[lb] = la;
        return la;
      }
    }
  };
}
int main(){
  int n; cin >> n;
  structure::dsu d(n);
  for (int i = 0; i < n; i++){
    int a, b; cin >> a >> b; a--; b--;
    d.merge(a, b);
  }
}
```

<a href = "https://github.com/tomo-224/klib/blob/main/type/structure.md">戻る</a>
