#include <vector>
#include <algorithm>

using ll = long long;

namespace structure {
  class mst {
  private:
    size_t size;
    std::vector<std::vector<ll>> data;
    std::vector<std::vector<ll>> sum;
    size_t width, height;
    void merge(size_t result) {
      size_t first = result << 1, second = (result << 1) + 1;
      size_t f = 0, s = 0;
      while (f != data[first].size() && s != data[second].size()) {
        if (data[first][f] < data[second][s]) {
          data[result].emplace_back(data[first][f]);
          ++f;
        }
        else {
          data[result].emplace_back(data[second][s]);
          ++s;
        }
      }
      data[result].insert(data[result].end(), data[first].begin() + f, data[first].end());
      data[result].insert(data[result].end(), data[second].begin() + s, data[second].end());
    }
  public:
    mst(std::vector<ll>& init) {
      size = init.size();
      width = 1, height = 1;
      while (width < size) {
        width <<= 1;
        height++;
      }
      data = std::vector<std::vector<ll>>(width*2, std::vector<ll>(0));
      for (size_t i = 0; i < size; i++) data[width+i] = std::vector<ll>(1, init[i]);
      for (size_t i = width-1; i >= 1; i--) merge(i);
      
      sum.resize(width*2);
      for (size_t i = 1; i < width*2; i++) {
        sum[i].resize(data[i].size()+1);
        sum[i][0] = 0;
        for (size_t j = 0; j < data[i].size(); j++) sum[i][j+1] = sum[i][j] + data[i][j];
      }
    }
    ll leq_amt(size_t l, size_t r, ll x) {
      ll ans = 0;
      l += width, r += width;
      for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans += std::upper_bound(data[l].begin(), data[l].end(), x) - data[l].begin(), ++l;
        if (r & 1) --r, ans += std::upper_bound(data[r].begin(), data[r].end(), x) - data[r].begin();
      }
      return ans;
    }
    
    ll leq_sum(size_t l, size_t r, ll x) {
      ll ans = 0;
      l += width, r += width;
      for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans += sum[l][std::upper_bound(data[l].begin(), data[l].end(), x) - data[l].begin()], ++l;
        if (r & 1) --r, ans += sum[r][std::upper_bound(data[r].begin(), data[r].end(), x) - data[r].begin()];
      }
      return ans;
    }
  };
}
