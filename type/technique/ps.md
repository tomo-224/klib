## 累積和

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n; cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<ll> s(n+1, 0);
  for (int i = 0; i < n; i++){
    s[i+1] = s[i] + v[i];
  }
}
```
