## Merge Sort Tree

### ソースコード $...$ <a href = "mst.hpp">mst.hpp</a>

### コンストラクタ
```cpp
//宣言
mst m(vector<ll>& init)
```
- `init` から、 Merge Sort Tree を構築します。
  - 以後、 `init` のサイズを $N$ と置きます。
- 計算量: $O(N \log N)$


### メンバ関数

**以下の個数**
```cpp
//leq_amt
ll leq_amt(ll l, ll r, ll x)
```
  - `init` の $[l, r)$ において $x$ 以下の要素の**個数**を求めます。
  - 計算量: $O(\log ^2 N)$
<br>

**以下の和**
```cpp
//leq_sum
ll leq_sum(ll l, ll r, ll x)
```
  - `init` の $[l, r)$ において $x$ 以下の要素の**和**を求めます。
  - 計算量: $O(\log ^2 N)$
<br>

### 参考
- https://atcoder.jp/contests/abc339/submissions/50918991

<a href = "https://github.com/tomo-224/klib/blob/main/type/structure.md">戻る</a>
