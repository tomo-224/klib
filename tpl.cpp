#ifndef MAIN
#define MAIN
#include __FILE__

//using namespace structure;
void _main(){
  
}

#else
#define MAIN
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
using modint10 = modint1000000007;
using motint9 = modint998244353;
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using strvec = vector<string>;

constexpr ll mod10 = 1000000007;
constexpr ll mod9 = 998244353;
constexpr ll inf = 10000000000000000;

#define int ll
#define double ld
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repf(i, s, n) for (int i = s; i < (int)(n); i++)
template <class... Args>
void __y_input(Args &...arg)
{
    (cin >> ... >> arg);
}

template <class... Args>
void __y_input_vec_1(int p, Args &...args)
{
    (cin >> ... >> args[p]);
}
template <class Arg>
void __y_input_vec_resize(int size, Arg &arg)
{
    arg.resize(size);
}
template <class... Args>
void __y_input_vec(int n, Args &...args)
{
    (__y_input_vec_resize(n, args), ...);
    rep(i, n)
    {
        (__y_input_vec_1(i, args), ...);
    }
}
#define cint(...)  \
    int __VA_ARGS__; \
    __y_input(__VA_ARGS__)

#define cdbl(...)     \
    double __VA_ARGS__; \
    __y_input(__VA_ARGS__)

#define cstr(...)     \
    string __VA_ARGS__; \
    __y_input(__VA_ARGS__)

#define cvec(n, ...)       \
    vector<int> __VA_ARGS__; \
    __y_input_vec(n, __VA_ARGS__)

#define cvect(t, n, ...) \
    vector<t> __VA_ARGS__; \
    __y_input_vec(n, __VA_ARGS__)

#define last cout << endl
#define yn(bl) (bl ? "Yes" : "No")
#define all(v) v.begin(), v.end()
#define acc(v) accumulate(v.begin(), v.end(), 0LL)
#define nxp(v) next_permutation(v.begin(), v.end())
ostream &yesno(bool bl)
{
    cout << yn(bl);
    return cout;
}
void cyn(bool bl){
    cout << (bl ? "Yes" : "No") << endl;
}
typedef array<int, 2> xy;
typedef array<int, 3> xyz;

template <typename T>
inline void sort(T &vec)
{
    return sort(vec.begin(), vec.end());
}
template <typename T>
inline void rsort(T &vec)
{
    return sort(vec.rbegin(), vec.rend());
}
void _main();

//original library
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
  
  struct w_dsu {
    vector<int> parent;
    vector<ll> weight;
    w_dsu(int n){
      parent = vector<int>(n, -1);
      weight = vector<ll>(n, 0);
    }
    int leader(int i){
      if (parent[i] < 0) return i;
      else {
        int ret = leader(parent[i]);
        weight[i] += weight[parent[i]];
        return parent[i] = ret;
      }
    }
    bool same(int a, int b){
      return (leader(a) == leader(b));
    }
    int size(int i){
      return -parent[leader(i)];
    }
    int merge(int a, int b, int w){
      int la = leader(a), lb = leader(b);
      if (la == lb) return (weight[a] - weight[b] == w ? la : -1);
      if (parent[la] >= parent[lb]){
        parent[lb] += parent[la];
        parent[la] = lb;
        weight[la] = weight[b] - weight[a] + w;
        return lb;
      }
      else {
        parent[la] += parent[lb];
        parent[lb] = la;
        weight[lb] = -(weight[b] - weight[a] + w);
        return la;
      }
    }
  };
  
  //template for rolling hash
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
  
  mint4 __rollinghash_addition(mint4 a, mint4 b){
    return a+b;
  }
  
  mint4 __rollinghash_zero(){
    mint4 ret;
    return ret;
  }
  
  using rollinghash_segtree = segtree<mint4, __rollinghash_addition, __rollinghash_zero>;
  class rollinghash{
    public:
      int size;
      vector<int> data;
      vector<mint4> pows;
      rollinghash(int dt, mint4 arg){
        size = dt;
        rnd = arg;
        data.resize(size);
        rec.set(1);
        rec = rec / rnd;
        pows = vector<mint4>(size+1);
        pows[0].set(1);
        for (int i = 1; i <= size; i++){
          pows[i] = pows[i-1] * rnd;
        }
        rollinghash_segtree tmp(size);
        seg = tmp;
      }
      rollinghash(int dt, mint4 arg, vector<int> init){
        size = dt;
        rnd = arg;
        data = init;
        rec.set(1);
        rec = rec / rnd;
        pows = vector<mint4>(size+1);
        pows[0].set(1);
        for (int i = 1; i <= size; i++){
          pows[i] = pows[i-1] * rnd;
        }
        vector<mint4> tm(size);
        for (int i = 0; i < size; i++) tm[i].set(init[i]);
        for (int i = 0; i < size; i++) tm[i] = tm[i] * pows[i];
        rollinghash_segtree tmp(tm);
        seg = tmp;
      }
    private: 
      rollinghash_segtree seg;
      mint4 rec;
      mint4 rnd;
    public:
      void reset(vector<int> m) {
        data = m;
        vector<mint4> vt(size);
        for (int i = 0; i < size; i++) vt[i].set(m[i]);
        for (int i = 0; i < size; i++){
          vt[i] = vt[i] * pows[i];
        }
        rollinghash_segtree tmp(vt);
        seg = tmp;
      }
      void set(int idx, int thing){
        mint4 tmp; tmp.set(thing);
        data[idx] = thing;
        seg.set(idx, tmp * pows[idx]);
      }
      mint4 get(int idx){
        return seg.get(idx);
      }
      mint4 prod(int l, int r){
        mint4 ans = seg.prod(l, r);
        ans = ans / pows[l];
        return ans;
      }
      mint4 all_prod(){
        return seg.all_prod();
      }
      mint4 roll(int l, int r, mint4 pre){
        //l, r は移動先 [l, r)
        mint4 left; left.set(data[l-1]);
        mint4 right; right.set(data[r-1]);
        return (((pre - left) + right * pows[r-l-1]) * rec);
      }
      mint4 in_roll(int l, int r, mint4 pre){
        //l, r は移動先 [l, r)
        mint4 left; left.set(data[l]);
        mint4 right; right.set(data[r]);
        return ((pre * rnd) - right * pows[r-l]) + left;
      }
  };
  
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

  struct bit {
    ull value = 0;
    
    //constructor
    bit(ull v = 0) : value(v) {};

    //operators
    bit& operator+=(const bit& other) { this->value += other.value; return *this; }
    bit& operator-=(const bit& other) { this->value -= other.value; return *this; }
    bit& operator*=(const bit& other) { this->value *= other.value; return *this; }
    bit& operator/=(const bit& other) { this->value /= other.value; return *this; }
    bit& operator%=(const bit& other) { this->value %= other.value; return *this; }
    bit& operator<<=(const bit& other) { this->value <<= other.value; return *this; }
    bit& operator>>=(const bit& other) { this->value >>= other.value; return *this; }
    bit& operator&=(const bit& other) { this->value &= other.value; return *this; }
    bit& operator|=(const bit& other) { this->value |= other.value; return *this; }
    bit& operator^=(const bit& other) { this->value ^= other.value; return *this; }
    bit& operator++() { value++; return *this; }
    bit operator++(signed) { bit tmp(value); value++; return tmp; }
    bit& operator--() { value--; return *this; }
    bit operator--(signed) { bit tmp(value); value--; return tmp; }
    const bool operator[](const std::size_t t) { return (this->value & (1ull << t)); }
    bit operator~() { return bit(~this->value); }
    explicit operator bool() { return (this->value != 0); }
    bit operator!() { return !bool(*this); }

    //member function
    void set(std::size_t pos, ull n) {
      value |= (1ull << pos);
      value &= (n << pos);
      return;
    }
    bool at(std::size_t pos) {
      return (value & (1 << pos));
    }
    bool next(const bit m) {
      value++;
      return (value < m.value);
    }
    ull& val(){
      return value;
    }
  };
  
  //operators
  std::istream& operator>>(std::istream& is, bit& b){
    return is >> b.val();
  }
  std::ostream& operator<<(std::ostream& os, bit& b){
    return os << b.val();
  }
  bit operator+(const bit& t1, const bit& t2) { return bit(t1) += t2; }
  bit operator-(const bit& t1, const bit& t2) { return bit(t1) -= t2; }
  bit operator*(const bit& t1, const bit& t2) { return bit(t1) *= t2; }
  bit operator/(const bit& t1, const bit& t2) { return bit(t1) /= t2; }
  bit operator%(const bit& t1, const bit& t2) { return bit(t1) %= t2; }
  bit operator<<(const bit& t, std::size_t n) { return bit(t) <<= n; }
  bit operator>>(const bit& t, std::size_t n) { return bit(t) >>= n; }
  bit operator&(const bit& t1, const bit& t2) { return bit(t1) &= t2; }
  bit operator^(const bit& t1, const bit& t2) { return bit(t1) ^= t2; }
  bit operator|(const bit& t1, const bit& t2) { return bit(t1) |= t2; }
  bool operator<(const bit& t1, const bit& t2) { return (t1.value < t2.value); }
  bool operator>(const bit& t1, const bit& t2) { return t2 < t1; }
  bool operator<=(const bit& t1, const bit& t2) { return !(t1 > t2); }
  bool operator>=(const bit& t1, const bit& t2) { return !(t1 < t2); }
  bool operator==(const bit& t1, const bit& t2) { return !(t1 < t2) && !(t2 > t2); }
  bool operator!=(const bit& t1, const bit& t2) { return !(t1 == t2); }
}

template <typename T>
void prefix_sum(vector<T>& p, vector<T>& s){
  s.emplace_back(p[0]);
  for (size_t i = 1; i < p.size(); i++){
    s.emplace_back(p[i] + s.back());
  }
  return;
}

template <typename T>
void compress(T a, T b){
  vector m(a, b);
  sort(all(m));
  m.erase(unique(all(m)), m.end());
  for (auto itr = a; itr != b; itr++){
    *itr = (lower_bound(all(m), *itr) - m.begin());
  }
}

template <typename T>
using rpq = priority_queue<T, vector<T>, greater<T>>;


signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    _main();
    return 0;
}

#endif
