# 遅延評価セグメント木 

## BETA

verify: https://atcoder.jp/contests/abc371/submissions/58427249

```cpp
#include <iostream>
#include <vector>
#include <cmath>

template <class S, S(*op)(S, S), S(*e)(), class F, S(*mapping)(F, S), F(*composition)(F, F), F(*id)()>

class lazy_segment_tree {

private:

    S _e;
    F _id;
    std::vector<S> data;
    std::vector<F> lazy;
    size_t width = 1;

    inline void propagate(int x) {

        data[x] = mapping(lazy[x], data[x]);
        if (x < width) {
            lazy[(x << 1)] = composition(lazy[x], lazy[(x << 1)]);
            lazy[(x << 1) + 1] = composition(lazy[x], lazy[(x << 1) + 1]);
        }
        lazy[x] = _id;

    }

    void apply_upper(int x) {

        if (!x) return;
        apply_upper(x >> 1);
        propagate(x);

    }

    inline void calc_upper(int x) {

        if (!x) return;
        propagate(x);
        if (x < width) data[x] = op(mapping(lazy[x << 1], data[x << 1]), mapping(lazy[(x << 1) + 1], data[(x << 1) + 1]));
        calc_upper(x >> 1);

    }

public:

    lazy_segment_tree(size_t size) {

        _e = e();
        _id = id();
        while (width < size) width <<= 1;
        data = std::vector<S>(width * 2, _e);
        lazy = std::vector<F>(width * 2, _id);

    }

    lazy_segment_tree(std::vector<S>& init) {

        _e = e();
        _id = id();
        while (width < init.size()) width <<= 1;
        data = std::vector<S>(width * 2, _e);
        lazy = std::vector<F>(width * 2, _id);

        for (int i = 0; i < init.size(); i++) data[i + width] = init[i];
        for (int i = width; --i;) data[i] = op(data[(i << 1)], data[(i << 1) + 1]);

    }

    S all_prod() {

        propagate(1);
        if (width != 1) data[1] = op(mapping(lazy[2], data[2]), mapping(lazy[3], data[3]));
        return data[1];

    }

    S prod(int l, int r) {

        S x = _e, y = _e;
        l += width, r += width;
        int L = l, R = r - 1;
        apply_upper(L);
        apply_upper(R);

        for (; l < r; l >>= 1, r >>= 1) {

            if (l & 1) {
                propagate(l);
                if (l < width) data[l] = op(mapping(lazy[l << 1], data[l << 1]), mapping(lazy[(l << 1) + 1], data[(l << 1) + 1]));
                x = op(x, data[l]);
                ++l;
            }

            if (r & 1) {
                --r;
                propagate(r);
                if (r < width) data[r] = op(mapping(lazy[r << 1], data[r << 1]), mapping(lazy[(r << 1) + 1], data[(r << 1) + 1]));
                y = op(data[r], y);
            }

        }

        calc_upper(L);
        calc_upper(R);
        return op(x, y);

    }

    void set(int i, S x) {

        i += width;
        apply_upper(i);
        data[i] = x;
        while (i >>= 1) data[i] = op(data[(i >> 1)], data[(i >> 1) + 1]);

    }

    S get(int i) {

        i += width;
        apply_upper(i);
        return data[i];

    }

    void apply(int l, int r, F f) {

        l += width, r += width;
        int L = l, R = r-1;
        apply_upper(L);
        apply_upper(R);

        for (; l < r; l >>= 1, r >>= 1) {

            if (l & 1) {
                propagate(l);
                if (l < width) data[l] = op(mapping(lazy[l << 1], data[l << 1]), mapping(lazy[(l << 1) + 1], data[(l << 1) + 1]));
                lazy[l] = f;
                ++l;
            }

            if (r & 1) {
                --r;
                propagate(r);
                if (r < width) data[r] = op(mapping(lazy[r << 1], data[r << 1]), mapping(lazy[(r << 1) + 1], data[(r << 1) + 1]));
                lazy[r] = f;
            }

        }

        calc_upper(L);
        calc_upper(R);

    }

    void err() {
        std::cerr << "data:\n";
        int cnt = 0;
        for (int i = 0; i < log2(width) + 1; i++) {
            for (int j = 0; j < (1 << i); j++) std::cerr << data[++cnt] << ' ';
            std::cerr << '\n';
        }
        std::cerr << std::endl;


        std::cerr << "lazy:\n";
        cnt = 0;
        for (int i = 0; i < log2(width) + 1; i++) {
            for (int j = 0; j < (1 << i); j++) std::cerr << lazy[++cnt] << ' ';
            std::cerr << '\n';
        }
        std::cerr << "\n\n" << std::flush;
    }

};
```
