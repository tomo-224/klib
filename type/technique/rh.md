## ローリングハッシュ
```cpp
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
namespace structure {
  using mint9 = modint998244353;
  using mint10 = modint1000000007;
  using mint19 = static_modint<1000000009>;
  using mint21 = static_modint<1000000021>;
  
  struct mint4{
    mint9 a=0; mint10 b=0; mint19 c=0; mint21 d=0;
    
    mint4(ll init = 0){
      set(init);
    }
    
    mint4 operator+(const mint4 &other) {
      mint4 ret;
      ret.a = a + other.a;
      ret.b = b + other.b;
      ret.c = c + other.c;
      ret.d = d + other.d;
      return ret;
    }
  
    mint4 operator-(const mint4 &other) {
      mint4 ret;
      ret.a = a - other.a;
      ret.b = b - other.b;
      ret.c = c - other.c;
      ret.d = d - other.d;
      return ret;
    }
    
    mint4 operator*(const mint4 &other) {
      mint4 ret;
      ret.a = a * other.a;
      ret.b = b * other.b;
      ret.c = c * other.c;
      ret.d = d * other.d;
      return ret;
    }
    
    mint4 operator/(const mint4 &other) {
      mint4 ret;
      ret.a = a / other.a;
      ret.b = b / other.b;
      ret.c = c / other.c;
      ret.d = d / other.d;
      return ret;
    }
    
    void set(int n){
      a = n;
      b = n;
      c = n;
      d = n;
    }
  
    void random_set(){
      random_device rd{};
      mt19937 mt(rd());
      a = mt();  b = mt();  c = mt();  d = mt();
    }
  };
  
  bool operator==(const mint4& t1, const mint4& t2) {
    return (t1.a == t2.a && t1.b == t2.b && t1.c == t2.c && t1.d == t2.d);
  }

  bool operator<(const mint4& t1, const mint4& t2) {
    if (t1.a != t2.a) return (t1.a.val() < t2.a.val());
    if (t1.b != t2.b) return (t1.b.val() < t2.b.val());
    if (t1.c != t2.c) return (t1.c.val() < t2.c.val());
    if (t1.d != t2.d) return (t1.d.val() < t2.d.val());
    return false;
  }
  
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
      assert(0 <= l && l < size);
      assert(0 < r && r <= size);
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
```
<a href = "https://github.com/tomo-224/klib/blob/main/type/technique.md">戻る</a>
