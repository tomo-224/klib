## 二分探索
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = LLONG_MAX / 2;
int main(){
  int n; cin >> n;
  /*操作...*/
  ll l = 0, r = inf; //適宜変更
  while (l + 1 < r){
    ll mid = (l+r)/2;
    //操作
    if (/*条件式*/) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
}
```
