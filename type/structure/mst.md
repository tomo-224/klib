## Merge Sort Tree
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()
namespace structure {
  void merge_arr(vector<ll>& ans, vector<ll>& a, vector<ll>& b) {
    ans = vector<ll>(0);
    size_t ai = 0, bi = 0;
    while (ai != a.size() || bi != b.size()) {
      if (ai == a.size()) {
        ans.push_back(b[bi]);
        bi++;
      }
      else if (bi == b.size()) {
        ans.push_back(a[ai]);
        ai++;
      }
      else {
        if (a[ai] < b[bi]) {
          ans.push_back(a[ai]);
          ai++;
        }
        else {
          ans.push_back(b[bi]);
          bi++;
        }
      }
    }
  }
  
  struct mst {
    vector<vector<vector<ll>>> data, sum;
    size_t depth, width;
    mst(vector<ll>& init) {
      depth = 0; width = 1;
      if (init.size() == 1) init.emplace_back(0);
      while (width < init.size()) {
        data.emplace_back(vector<vector<ll>>(width, vector<ll>(1, 0)));
        depth++; width *= 2;
      }
      data.emplace_back(vector<vector<ll>>(width, vector<ll>(1, 0)));
      depth++;
      for (size_t i = 0; i < init.size(); i++) {
        data[depth - 1][i].emplace_back(init[i]);
      }
      for (int i = depth - 2; i >= 0; i--) for (int j = 0; j < ll(data[i].size()); j++) merge_arr(data[i][j], data[i + 1][j * 2], data[i + 1][j * 2 + 1]);
      //ABC339-G用 必要に応じて削除
      sum = data;
      for (auto& vv : sum) for (auto& v : vv) for (int i = 1; i < ll(v.size()); i++) v[i] += v[i - 1];
    }
    ll lower_sum(ll lef, ll rig, ll x) {
      return sum_(lef, rig, 0, width, 0, x);
    }
    ll sum_(ll lef, ll rig, ll a, ll z, ll i, ll x) {
      ll ret;
      if (rig <= a || z <= lef) ret = 0LL;
      else if (lef <= a && z <= rig) {
        ll idx = upper_bound(all(data[i][a >> (depth - i - 1)]), x) - data[i][a >> (depth - i - 1)].begin() - 1;
        ret = sum[i][a >> (depth - i - 1)][idx];
      }
      else ret = sum_(lef, rig, a, z - (width >> (i + 1)), i + 1, x) + sum_(lef, rig, z - (width >> (i + 1)), z, i + 1, x);
      return ret;
    }
    
    ll lower_amt(ll lef, ll rig, ll x) {
      return amt_(lef, rig, 0, width, 0, x);
    }
    ll amt_(ll lef, ll rig, ll a, ll z, ll i, ll x) {
      ll ret;
      if (rig <= a || z <= lef) ret = 0LL;
      else if (lef <= a && z <= rig) {
        ret = upper_bound(all(data[i][a >> (depth - i - 1)]), x) - data[i][a >> (depth - i - 1)].begin() - 1;
      }
      else ret = amt_(lef, rig, a, z - (width >> (i + 1)), i + 1, x) + amt_(lef, rig, z - (width >> (i + 1)), z, i + 1, x);
      return ret;
    }
  };
}

int main() {
  int n; cin >> n;
  vector<ll> v(n);
  for (auto& p : v) cin >> p;
  structure::mst t(v);
  ll p = 0;
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    ll a, b, c; cin >> a >> b >> c;
    ll l = a xor p, r = b xor p, x = c xor p;
    p = t.lower_sum(l - 1, r, x);
    cout << p << endl;
  }
}
```
<a href = "https://github.com/tomo-224/klib/blob/main/type/structure.md">戻る</a>
