#include <vector>

template <class T, T (*add)(T, T), T(*sub)(T, T), T (*e)()>
class prefix_sum_2D {
private:
  std::size_t height, width;
  std::vector<std::vector<T>> data, sum;
public:
  prefix_sum_2D(std::size_t h, std::size_t w) : height(h), width(w) {
    sum = data = std::vector<std::vector<T>>(height, std::vector<T>(width, e()));
  }
  prefix_sum_2D(std::vector<std::vector<T>> &v) : data(v) {
    height = v.size();
    width = (v.empty() ? size_t(0) : v[0].size());
    sum = std::vector<std::vector<T>>(height+1, std::vector<T>(width+1, e()));
    if (v.empty()) return;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        sum[i+1][j+1] = add(sub(add(sum[i+1][j], sum[i][j+1]), sum[i][j]), v[i][j]);
      }
    }
  }
  int get(int i, int j) {
    return data[i][j];
  }
  int prod(int u, int d, int l, int r) {
    if (u >= d || l >= r) return e();
    return add(sub(sub(sum[d][r], sum[d][l]), sum[u][r]), sum[u][l]);
  }
};
