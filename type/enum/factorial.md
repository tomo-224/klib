## 階乗

### ソースコード（<a href = "n_fact.md">N 重階乗</a>と共通） $...$ <a href = "factorial.cpp">factorial.hpp</a>

### コンストラクタ
```cpp
//宣言
factorial<T> fact(size_t N);
```
- `T` は計算結果を補完する型
- `N` は計算する最大値

- 計算量: $O(N)$（掛け算の計算量が $O(1)$ のとき）

### メンバ関数
**計算**
```cpp
// calculate
T f(int x)
```
- $x!$ を返します。
- 計算量: $O(1)$

<a href = "https://github.com/tomo-224/klib/blob/main/type/enum.md">戻る</a>
