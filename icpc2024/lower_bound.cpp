#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct X {
  int id;
  std::string name;
};

int main()
{
  // この関数単体としての使い方
  {
    // lower_bound で 4 以上の要素の位置を検索する場合、
    // 4 より小さい物と 4 以上の物がその順に並んでいれば、
    // 必ずしもソートされている必要はない。
    std::vector<int> v = {3, 1, 4, 6, 5};

    // 4以上の要素を二分探索で検索
    decltype(v)::iterator it = std::lower_bound(v.begin(), v.end(), 4);
    if (it != v.end()) {
      std::size_t pos = std::distance(v.begin(), it);
      std::cout << *it << " pos=" << pos << std::endl;
    }
  }

  // 基本的な用途
  // ソート済みイテレータ範囲から、特定の値を二分探索で見つける
  {
    std::vector<int> v = {3, 1, 4, 6, 5};
    std::sort(v.begin(), v.end());

    // 二分探索で値4を検索
    decltype(v)::iterator it = std::lower_bound(v.begin(), v.end(), 4);
    if (it != v.end() && *it == 4) { // lower_boundでは4"以上"の値が見つかるので、
                                     // 値4を見つけたいなら検索結果の値を比較する必要がある
      std::size_t pos = std::distance(v.begin(), it);
      std::cout << *it << " pos=" << pos << std::endl;
    }
  }

  // 要素の一部の値を比較して見つける
  {
    // 要素は複数のメンバ変数をもつ
    std::vector<X> v = {
      {1, "Bob"},
      {3, "Alice"},
      {4, "Carol"},
      {2, "Franklin"},
      {5, "Eve"},
      {6, "Dave"}
    };

    const std::string key = "Carol";

    // X::nameメンバ変数をキーにして、
    // X::name == "Carol"となる要素を二分探索で見つける
    decltype(v)::iterator it = std::lower_bound(
      v.begin(),
      v.end(),
      X{-1, key}, // nameのみを比較するので、idの値はなんでもよい
      [](const X& a, const X& b) { return a.name < b.name; }
    );

    if (it != v.end() && it->name == key) {
      std::size_t pos = std::distance(v.begin(), it);
      std::cout << "id=" << it->id
                << " name=" << it->name
                << " pos=" << pos
                << std::endl;
    }
  }
}