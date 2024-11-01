#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace structure {
  // need modint, mint4
  struct str_hash {
    size_t size;
    mint4 rnd, rrnd;
    string data;
    vector<mint4> mp, rmp;
    vector<mint4> prefix, suffix;
    str_hash(size_t z = 0, mint4 r = mint4(0), string d = "") : size(z), rnd(r), data(d) {
      if (z != 0) {
        rrnd = mint4(1) / rnd;
        mp = rmp = vector<mint4>(z, mint4(1));
        for (size_t i = 1; i < z; i++) mp[i] = mp[i-1] * rnd;
        for (size_t i = 1; i < z; i++) rmp[i] = rmp[i-1] * rrnd;
        prefix = suffix = vector<mint4>(z, mint4(0));
        prefix[0].set(data[0]);
        for (size_t i = 1; i < z; i++) prefix[i] = prefix[i-1] * rnd + mint4(data[i]);
        suffix[z-1].set(data.back());
        for (int i = z-2; i >= 0; i--) suffix[i] = mint4(data[i]) * mp[z-i-1] + suffix[i + 1];
      }
    }
    str_hash(size_t z, mint4 r, string d, vector<mint4>& mi, vector<mint4>& rmi) : size(z), rnd(r), data(d), mp(mi), rmp(rmi) {
      rrnd = mint4(1) / rnd;
      if (z != 0) {
        prefix = suffix = vector<mint4>(z, mint4(0));
        prefix[0].set(data[0]);
        for (size_t i = 1; i < z; i++) prefix[i] = prefix[i-1] * rnd + mint4(data[i]);
        suffix[z-1].set(data.back());
        for (int i = z-2; i >= 0; i--) suffix[i] = mint4(data[i]) * mp[z-i-1] + suffix[i + 1];
      }
    }
    mint4 hash(int l, int r){
      if (l == r) return mint4(0);
      assert(0 <= l && l < ll(size));
      assert(0 < r && r <= ll(size));
      assert(l < r);
      return prefix[r-1] - (l == 0 ? mint4(0) : prefix[l-1]) * mp[r-l];
    }
    mint4 roll(int l, int r, int dist){
      return hash(l+dist, r+dist);
    }
  };
}

int main(){
  string s = "123456789";
  structure::mint4 rnd; rnd.set(2);
  structure::str_hash h(s.size(), rnd, s);
  for (int i = 0; i < s.size()-3; i++) cerr << h.hash(i, i+4).a.val() << endl;
  for (auto k : s) cout << int(k) << endl;
}
