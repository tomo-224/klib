## 累積和

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
void prefix_sum(vector<T>& p, vector<T>& s){
  s.emplace_back(p[0]);
  for (size_t i = 1; i < p.size(); i++){
    s.emplace_back(p[i] + s.back());
  }
  return;
}

int main(){
  int n; cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<ll> s(n+1, 0);
  for (int i = 0; i < n; i++){
    s[i+1] = s[i] + v[i];
  }
  vector<ll> t(1, 0);
  prefix_sum(v, t);
}
```

<a href = "https://github.com/tomo-224/klib/blob/main/type/technique.md">戻る</a>
