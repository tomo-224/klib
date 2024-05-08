## 二次元累積和
### ソースコード $...$ <a href = "prefix_sum_2D.hpp">prefix_sum_2D.hpp</a>
### コンストラクタ
```cpp
//宣言
prefix_sum_2D<class S, S (*add)(S, S), S (*sub)(S, S), S (*e)()> seg(int h, int w)
prefix_sum_2D<class S, S (*add)(S, S), S (*sub)(S, S), S (*e)()> seg(vector<vector<S>> v)
```
- `S` は型
- `add` は取得用の二項演算
  　- `sub` は `add` の逆の演算 (たとえば、 `add` が足し算のとき、 `sub` は引き算)
- `e()` は単位元
  - 長さ `h`, 幅 `w`, 初期値 `e()` の二次元配列から累積和を構築します。
  - 要素の初期値が `v` から累積和を構築します。

- 計算量: $O(HW)$


### メンバ関数
通常の累積和を二次元に拡張したものです。

**要素取得**
```cpp
//get
S get(int x, int y)
```
  - `x` 行 `y` 列の要素を取得します。
  - 計算量: $O(1)$
<br>

**範囲取得**
```cpp
//prod
S prod(int u, int d, int l, int r)
```
  - `u` 行目から `d - 1` 行目まで、`l` 列目から `r - 1` 列目までで表される、長方形の領域について `add` を計算し、結果を返します。
  - 計算量: $O(1)$
<br>

<a href = "https://github.com/tomo-224/klib/blob/main/type/structure.md">戻る</a>
