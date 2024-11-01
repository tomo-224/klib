#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace structure {
  template <class S, S (*op)(S, S), S (*e)()>
  struct Segtree {
      std::vector<S> Tree;
      int n;
      int depth = 1, width = 1;
      Segtree(int N = 0) : n(N) {
          while (width < n) depth++, width <<= 1;
          Tree.resize(width * 2);
          for (int i = width; i < width * 2; i++) Tree[i] = e();
          for (int i = width-1; i >= 0; i--) Tree[i] = op(Tree[i<<1], Tree[i<<1|1]);
      }
      Segtree(std::vector<S> v) {
          n = v.size();
          while (width < n) depth++, width <<= 1;
          Tree.resize(width * 2);
          for (int i = width; i < width * 2; i++) Tree[i] = (i < width + n ? v[i - width] : e());
          for (int i = width-1; i >= 0; i--) Tree[i] = op(Tree[i<<1], Tree[i<<1|1]);
      }
      void set(int pos, S val) {
          pos += width;
          Tree[pos] = val;
          for (int c = (pos >> 1); c > 0; c >>= 1) Tree[c] = op(Tree[c<<1], Tree[c<<1|1]);
          return;
      }
      S get(int pos) { return Tree[width + pos]; }
      S all_prod() { return Tree[1]; }
      S prod(int l, int r) {
          S x = e(), y = e();
          l += width, r += width;
          for (; l < r; l >>= 1, r >>= 1) {
              if (l & 1) x = op(x, Tree[l++]);
              if (r & 1) y = op(Tree[--r], y);
          }
          return op(x, y);
      }
  };
  
  template <int MOD>
  class modint
  {
  public:
  	modint() : n(0) {}
  	modint(int n) : n(n) {}
  	modint &operator+=(modint const &other)
  	{
  		n += other.n;
  		if (n >= MOD)
  			n -= MOD;
  		return *this;
  	}
  	inline modint &operator-=(modint const &other)
  	{
  		return *this += MOD - other.n;
  	}
  	modint &operator*=(modint const &other)
  	{
  		n = (long long)n * other.n % MOD;
  		return *this;
  	}
  	inline modint &operator/=(modint const &other)
  	{
  		return *this *= other.inv();
  	}
  	inline modint operator+(modint const &other) const
  	{
  		return modint(*this) += other;
  	}
  	inline modint operator-(modint const &other) const
  	{
  		return modint(*this) -= other;
  	}
  	inline modint operator*(modint const &other) const
  	{
  		return modint(*this) *= other;
  	}
  	inline modint operator/(modint const &other) const
  	{
  		return modint(*this) /= other;
  	}
  	modint pow(int k) const
  	{
  		modint x = *this, res = 1;
  		while (k)
  		{
  			if (k & 1)
  				res *= x;
  			x *= x;
  			k >>= 1;
  		}
  		return res;
  	}
  	inline modint inv() const
  	{
  		return pow(MOD - 2);
  	}
  	inline int val() const
  	{
  		return n;
  	}
  	inline bool operator==(modint const &other) const
  	{
  		return n == other.n;
  	}
  	inline bool operator!=(modint const &other) const
  	{
  		return n != other.n;
  	}
  	inline modint operator+() const
  	{
  		return *this;
  	}
  	inline modint operator-() const
  	{
  		return modint(0) - *this;
  	}
  
  private:
  	int n;
  };

  using mint9 = modint<998244353>;
  using mint10 = modint<1000000007>;
  using mint19 = modint<1000000009>;
  using mint21 = modint<1000000021>;
  
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
  
  using rollinghash_segtree = Segtree<mint4, __rollinghash_addition, __rollinghash_zero>;
  class rollinghash{
    private: 
      rollinghash_segtree seg;
      mint4 rnd;
    public:
      //member variable
      int size;
      vector<int> data;
      vector<mint4> pows;
      mint4 rec;
      //constructor
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
      //member function
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
      mint4 next(int l, int r, mint4 pre){
        //l, r は移動先 [l, r)
        mint4 left, right; 
        left.set(data[l-1]);
        right.set(data[r-1]);
        return (((pre - left) + right * pows[r-l-1]) * rec);
      }
      mint4 prev(int l, int r, mint4 pre){
        //l, r は移動先 [l, r)
        mint4 left, right;
        left.set(data[l]);
        right.set(data[r]);
        return ((pre * rnd) - right * pows[r-l]) + left;
      }
  };
}

int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(s.begin(), s.end());
  auto b = a;
  reverse(b.begin(), b.end());
  structure::mint4 rnd; rnd.random_set();
  structure::rollinghash rh(n*2, rnd, a), rhr(n*2, rnd, b);
  structure::mint4 m = rh.prod(0, n);
}
