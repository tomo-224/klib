## 座標圧縮
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

template <typename T>
void compress(vector<T>::iterator a, vector<T>::iterator b){
  vector<T> m(a, b);
  sort(all(m));
  m.erase(unique(all(m)), m.end());
  for (auto itr = a; itr != b; itr++){
    itr* = lower_bound(all(m), itr*) - m.begin();
  }
}

int main(){
  int n; cin >> n;
  vector<ll> v(n); for (auto& p : v) cin >> p;
  auto w = v;
  auto a = v;
  sort(a);
  a.erase(unique(all(a)), a.end());
  for (int i = 0; i < n; i++) {
    v[i] = lower_bound(all(a), r[i]) - a.begin();
  }
  for (auto k : v) cout << k << " ";
  cout << endl;
  compress(all(w));
  for (auto k : w) cerr << k << " ";
  cerr << endl;
}
```

<a href = "https://github.com/tomo-224/klib/blob/main/type/technique.md">戻る</a>
