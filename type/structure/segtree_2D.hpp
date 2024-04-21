#include <vector>

template <class S, S (*op)(S, S), S (*e)()>
struct Segtree_2D {
    std::vector<std::vector<S>> Tree;
    int height, width;
    S e_;
    Segtree_2D(int h, int w) {
        e_ = e();
        height = width = 1;
        while (height < h) height <<= 1;
        while (width < w) width <<= 1;
        Tree = std::vector<std::vector<S>>(height<<1, std::vector<S>(width<<1, e_));
    }
    Segtree_2D(std::vector<std::vector<S>> v) {
        e_ = e();
        int h = v.size(), w = v.back().size();
        height = width = 1;
        while (height < h) height <<= 1;
        while (width < w) width <<= 1;
        Tree = std::vector<std::vector<S>>(height<<1, std::vector<S>(width<<1, e_));
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) Tree[height + i][width + j] = v[i][j];
        for (int i = height; i < (height<<1); i++) for (int j = width-1; j >= 0; j--) Tree[i][j] = op(Tree[i][j<<1], Tree[i][j<<1|1]);
        for (int j = 0; j < (width<<1); j++) for (int i = height-1; i >= 0; i--) Tree[i][j] = op(Tree[i<<1][j], Tree[i<<1|1][j]);
    }
    void set(int x, int y, S val) {
        x += height; y += width;
        Tree[x][y] = val;
        for (int c = (x >> 1); c > 0; c >>= 1) {
            Tree[c][y] = op(Tree[c<<1][y], Tree[c<<1|1][y]);
            for (int d = (y >> 1); d > 0; d >>= 1) {
                Tree[c][d] = op(Tree[c][d<<1], Tree[c][d<<1|1]);
            }
        }
        return;
    }
    S get(int x, int y) { return Tree[height + x][width + y]; }
    S all_prod() { return Tree[1][1]; }
    S prod(int u, int d, int l, int r) {
        S a = e_, b = e_;
        u += height, d += height;
        for (; u < d; u >>= 1, d >>= 1) {
            if (u & 1) {
                S x = e_, y = e_;
                int L = l, R = r;
                L += width, R += width;
                for (; L < R; L >>= 1, R >>= 1) {
                    if (L & 1) x = op(x, Tree[u][L++]);
                    if (R & 1) y = op(Tree[u][--R], y);
                }
                a = op(a, op(x, y));
                u++;
            }
            if (d & 1) {
                --d;
                S x = e_, y = e_;
                int L = l, R = r;
                L += width, R += width;
                for (; L < R; L >>= 1, R >>= 1) {
                    if (L & 1) x = op(x, Tree[d][L++]);
                    if (R & 1) y = op(Tree[d][--R], y);
                }
                b = op(op(x, y), b);
            }
        }
        return op(a, b);
    }
};
