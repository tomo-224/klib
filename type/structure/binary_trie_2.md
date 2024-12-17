## binary_trie (下の bit から)

## BETA

### ソースコード $...$ <a href = "binary_trie_2.ipp">binary_trie_2.ipp</a>
### コンストラクタ
```cpp
//宣言
binary_trie<T> e()
binary_trie<T> e(Iterator& begin, Iterator& end)
```
- `T` は型
- 2 つ目のコンストラクタでは、`begin` ~ `end` の要素を予めすべて `insert` した状態にする
  - 計算量: $O(N * sizeof(T))$


### メンバ関数
2024/12/17 現在 `insert` のみ対応

<a href = "binary_trie.md">binary_trie</a><br />
<a href = "https://github.com/tomo-224/klib/blob/main/type/structure.md">戻る</a>
