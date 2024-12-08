## 演算付き Union-Find

### コンストラクタ
```cpp
//宣言
dsu_t<class S, class T, T (*op)(S&, S&), S (*e)()> d(int n);
dsu_t<class S, class T, T (*op)(S&, S&), S (*e)()> d(vector<S> init);
```
- `S` は型
- `T` はマージ時の演算結果の型
- `op()` はマージ時の演算
  - 1 つ目の引数に 2 つ目の引数をマージした結果を格納します。
  - 結果は `T` 型で、`merge` 関数の返り値となります。
- `e()` は単位元

- 計算量: $O(HW)$


### メンバ関数
ほとんど ACL と共通です。。

**データ変更**
```cpp
//set
void set(int i, S n)
```
  - `i` 番目のデータを `n` に変更します。
  - 計算量: $O(1)$
<br>

### ソースコード
```cpp
namespace structure {
  template<class S, class T, T (*op)(S&, S&), S (*e)()>
  struct dsu_t {
    vector<int> parent;
    S e_;
    vector<S> data;
    
    dsu_t(int n){
      parent = vector<int>(n, -1);
      e_ = e();
      data = vector<S>(n, e_);
    }
    
    dsu_t(vector<S> init) : data(init) {
      parent = vector<int>(init.size(), -1);
      e_ = e();
    }
    
    void set(int i, S n) {
      data[i] = n;
    }
    
    int leader(int i){
      if (parent[i] < 0) return i;
      else return parent[i] = leader(parent[i]);
    }
    
    bool same(int a, int b){
      return (leader(a) == leader(b));
    }
    
    int size(int i){
      return -parent[leader(i)];
    }
    
    T merge(int a, int b){
      int la = leader(a), lb = leader(b);
      if (la == lb) return la;
      if (size(la) > size(lb)) swap(la, lb);
      parent[la] += parent[lb];
      parent[lb] = la;
      T ret = op(data[la], data[lb]);
      data[lb] = e_;
      return ret;
    }
    
  };
}
```

<a href = "https://github.com/tomo-224/klib/blob/main/type/structure.md">戻る</a>
