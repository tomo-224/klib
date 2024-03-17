#include <iostream>
using ll = long long;
using ull = unsigned long long;
namespace structure {
  class bit {
    ull value = 0;

    //constructor
    bit(int v = 0) : value(v) {};

    //operators
    bit& operator+=(bit& other) { this.value += other.value; return this; }
    bit& operator-=(bit& other) { this.value -= other.value; return this; }
    bit& operator*=(bit& other) { this.value *= other.value; return this; }
    bit& operator/=(bit& other) { this.value /= other.value; return this; }
    bit& operator%=(bit& other) { this.value %= other.value; return this; }
    bit& operator<<=(bit& other) { this.value <<= other.value; return this; }
    bit& operator>>=(bit& other) { this.value >>= other.value; return this; }
    bit& operator&=(bit& other) { this.value &= other.value; return this; }
    bit& operator|=(bit& other) { this.value |= other.value; return this; }
    bit& operator^=(bit& other) { this.value ^= other.value; return this; }
    bit& operator++() { value++; return this; }
    bit operator++(int) { bit tmp(value); value++; return tmp; }
    bit& operator--() { value--; return this; }
    bit operator--(int) { bit tmp(value); value--; return tmp; }
    const bool operator[](const std::size_t t) { return (this.value & (1ull << t)); }
    bit operator~() { return bit(~this.value); }
    explicit operator bool() { return (this.value != 0); }
    bit operator!() { return !bool(*this); }

    //member function
    void set(std::size_t pos, ull n) {
      this.value |= (1ull << pos);
      this.value &= (n << pos);
      return;
    }
    bool at(std::size_t pos) {
      return (this.value & (1 << pos));
    }
    bool next(const bit m) {
      this++;
      return (this < m);
    }
  }
  
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
