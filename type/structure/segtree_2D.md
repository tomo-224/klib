## 2D Segment Tree(二次元セグメント木)
### ソースコード $...$ <a href = "segtree_2D.hpp">segtree_2D.hpp</a>
### コンストラクタ
```cpp
//宣言
Segtree_2D<class S, S (*op)(S, S), S (*e)()> seg(int h, int w)
Segtree_2D<class S, S (*op)(S, S), S (*e)()> seg(vector<vector<S>> v)
```
- `S` は型
- `op` は取得用の二項演算
- `e()` は単位元
  - 長さ `h`, 幅 `w`, 初期値 `e()` の2次元セグメントツリーを構築します。
  - 要素の初期値が `v` の内容となる2次元セグメントツリーを構築します。

- 計算量: $O(HW)$


### メンバ関数
主に、 <a href = "segtree.md">Segment Tree</a> を二次元に拡張したものです。

**要素変更**
```cpp
//set
void set(int x, int y, S val)
```
  - `x` 行 `y` 列の要素を `val` に変更します。
  - 計算量: $O(\log H \log W)$
<br>

**要素取得**
```cpp
//get
S get(int x, int y)
```
  - `x` 行 `y` 列の要素を取得します。
  - 計算量: $O(1)$
<br>

**全体取得**
```cpp
//all_prod
S all_prod()
```
  - 要素全体について `op` の計算をした結果を返します。
  - 計算量: $O(1)$
<br>

**範囲取得**
```cpp
//prod
S prod(int u, int d, int l, int r)
```
  - `u` 行目から `d - 1` 行目まで、`l` 列目から `r - 1` 列目までで表される、長方形の領域について `op` を計算し、結果を返します。
  - 計算量: $O(\log H \log W)$
<br>

<a href = "https://github.com/tomo-224/klib/blob/main/type/structure.md">戻る</a>
