## bit
### ソースコード $...$ <a href = "bit.hpp">bit.hpp</a>
### コンストラクタ
```cpp
//宣言
structure::bit b(ull n)
```
- $n$ は初期値です。

### 演算
通常の整数型とほぼ同じことができます。
- 算術
- 代入
- 複合代入
- ビット演算
- ビット否定
- 論理否定
- 等価/非等価比較
- bool型へのキャスト

また、特有のものとして次の演算を提供しています。
- 添字 $...$ 特定のビットにアクセスします。

### 入出力
通常の整数型と同様の入出力が可能です。
```cpp
//入力
std::istream >> b
```
```cpp
//出力
std::ostream << b
```

### メンバ関数
通常の整数型にはない、特有のメンバ関数を提供しています。

**ビット変更**
```cpp
//set
void set(std::size_t pos, ull n)
```
  - 下から`pos`番目のビットを`n`に変更します。
<br>

**ビットアクセス**
```cpp
//at
bool at(std::size_t pos)
```
  - 「下からpos番目のbitが立っているか？」を真偽値として返します。
<br>

**インクリメント**
```cpp
//next
bool set(const bit m)
```
  - 自身をインクリメントします。
  - もし`m`以上であれば、`false`を返します。
  - do_while文とともに使うことができます。
<br>

**値取得**
```cpp
//val
ull& val()
```
  - 内部の値そのものを返します。
<br>

**二進変換**
```cpp
//bin
string bin()
```
  - 内部の値を二進数で表した文字列を返します。デバッグ用です。
<br>

**立ったビット数**
```cpp
//count
int count()
```
  - 立っている(1になっている)ビットの数を数えます。
<br>

<a href = "https://github.com/tomo-224/klib/blob/main/type/structure.md">戻る</a>
