## 階乗

### ソースコード（<a href = "factorial.ipp">factorial.ipp</a>を要求） $...$ <a href = "combination.ipp">combination.ipp</a>

```cpp
T comb(factorial<T>& fact, int entire, int part)
```
${}_n \mathrm{C}_k$ を計算します。
- `fact` ... 階乗の構造体（参照）
- `entire` ... $n$
- `part` ... $k$

- 計算量 ... $O(1)$（掛け算の計算量が $O(1)$ のとき）

<a href = "https://github.com/tomo-224/klib/blob/main/type/enum.md">戻る</a>
