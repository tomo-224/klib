## N 重階乗

### ソースコード（<a href = "factorial.md">階乗</a>と共通） $...$ <a href = "factorial.ipp">factorial.ipp</a>

### コンストラクタ
```cpp
//宣言
factorial<T, int d> fact(size_t N);
```
- `T` は計算結果を補完する型
- `d` は何重階乗か
- `N` は計算する最大値

- 計算量: $O(N)$（掛け算の計算量が $O(1)$ のとき）

### メンバ関数
**計算**
```cpp
// calculate
T f(int x)
```
- $x$ の N 重階乗を返します。
- 計算量: $O(1)$

<a href = "https://github.com/tomo-224/klib/blob/main/type/enum.md">戻る</a>
