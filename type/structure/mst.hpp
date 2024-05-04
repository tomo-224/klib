#include <vector>
#include <algorithm>

using ll = long long;
#define all(v) v.begin(), v.end()

namespace structure {
  void merge_arr(std::vector<ll>& ans, std::vector<ll>& a, std::vector<ll>& b) {
    ans = std::vector<ll>(0);
    std::size_t ai = 0, bi = 0;
    while (ai != a.size() || bi != b.size()) {
      if (ai == a.size()) {
        ans.emplace_back(b[bi]);
        bi++;
      }
      else if (bi == b.size()) {
        ans.emplace_back(a[ai]);
        ai++;
      }
      else {
        if (a[ai] < b[bi]) {
          ans.emplace_back(a[ai]);
          ai++;
        }
        else {
          ans.emplace_back(b[bi]);
          bi++;
        }
      }
    }
  }
  
  struct mst {
    std::vector<std::vector<std::vector<ll>>> data, sum;
    std::size_t depth, width;
    mst(std::vector<ll>& init) {
      depth = 0; width = 1;
      if (init.size() == 1) init.emplace_back(0);
      while (width < init.size()) {
        data.emplace_back(std::vector<std::vector<ll>>(width, std::vector<ll>(1, 0)));
        depth++; width *= 2;
      }
      data.emplace_back(std::vector<std::vector<ll>>(width, std::vector<ll>(1, 0)));
      depth++;
      for (std::size_t i = 0; i < init.size(); i++) {
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
        ll idx = std::upper_bound(all(data[i][a >> (depth - i - 1)]), x) - data[i][a >> (depth - i - 1)].begin() - 1;
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
        ret = std::upper_bound(all(data[i][a >> (depth - i - 1)]), x) - data[i][a >> (depth - i - 1)].begin() - 1;
      }
      else ret = amt_(lef, rig, a, z - (width >> (i + 1)), i + 1, x) + amt_(lef, rig, z - (width >> (i + 1)), z, i + 1, x);
      return ret;
    }
  };
}
