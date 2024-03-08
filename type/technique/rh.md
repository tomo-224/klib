## ローリングハッシュ
```cpp
#include <bits/stdc++.h>
using namespace std;
namespace structure {
  struct str_hash {
    mint4 rnd;
    string data;
    vector<mint4> mp, rmp;
    vector<mint4> prefix, suffix;
    size_t size;
    str_hash(size_t z, mint4 r, string d) : size(z), rnd(r), data(d) {
      rrnd = mint4(1) / rnd;
    }
  }
}
```
