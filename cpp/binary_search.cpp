#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// 用std::lower_bound实现二分查找。
template<typename ForwardIt, typename T, typename Compare=std::less<>>
ForwardIt binary_find(ForwardIt first, ForwardIt last, const T& value, Compare comp={}) {
    first = std::lower_bound(first, last, value, comp);
    // first != last不代表找到了。可能第一个元素就>*first。
    return first != last && !comp(*first, value) ? first : last;
}

struct S {
  int a;
  int b;
};

static bool comp_s(const S &s1, int val) {
  return s1.a < val;
}

int main() {
  vector<S> v;
  v.push_back({1,2});
  v.push_back({2,3});
  v.push_back({3,4});
  v.push_back({4,5});
  v.push_back({5,6});
  
  auto it = binary_find(v.cbegin(), v.cend(), 3, comp_s);
  cout << it->a << endl;
  cout << std::distance(v.cbegin(), it) << endl;


  int a[] = {1, 2, 3, 4 ,5 ,6};
  auto it2 = binary_find(&a[0], &a[5], 4);
  cout << *it2 << endl;
  cout << std::distance(&a[0], it2) << endl;
}