#include <random>
#include <vector>

using namespace std;
using ll = long long;

namespace structure {
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
}
