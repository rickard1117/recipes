#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// 用std::lower_bound实现二分查找。
//template<typename ForwardIt, typename T, typename Compare=std::less<>>
//ForwardIt binary_find(ForwardIt first, ForwardIt last, const T &value, Compare comp={}) {
//    first = std::lower_bound(first, last, value, comp);
//    // first != last不代表找到了。可能第一个元素就>*first。
//    return first != last && !comp(value, first) ? first : last;
//}

// 针对raw类型数组的二分查找. 错误的版本。
//template<typename T, typename Compare=std::less<>>
//int array_binary_find(T *array, int size, const T &value, Compare comp={}) {
//   int count = size, step = 0, right = 0, left = 0;
//   while (count > 0) {
//     right = left;
//     step = count / 2;
//     right += step;
//     if (comp(array[right], value)) {
//       left = ++right;
//       count -= step + 1;
//     } else {
//       count = step;
//     }
//   }
//   return comp(array[left], value)? -1 : left;
//}

template<typename T>
int array_binary_find(T *array, int size, const T &value) {
  int left = 0, right = size - 1, mid = 0;
  while (left <= right) {
    mid = (left + right) / 2;
    if (array[mid] == value) {
      return mid;
    } else if (array[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}


struct S {
  int a;
  int b;
};

//static bool comp_s(const S &s1, int val) {
//  return s1.a < val;
//}

int main() {
//  vector<S> v;
//  v.push_back({1,2});
//  v.push_back({2,3});
//  v.push_back({3,4});
//  // v.push_back({4,5});
//  v.push_back({5,6});
//
//  auto it = binary_find(v.cbegin(), v.cend(), 3, comp_s);
//  cout << it->a << endl;
//  cout << std::distance(v.cbegin(), it) << endl;
//
//  it = binary_find(v.cbegin(), v.cend(), 4, comp_s);
//  cout << it->a << endl;
//  cout << std::distance(v.cbegin(), it) << endl;
//
//  it = binary_find(v.cbegin(), v.cend(), 6, comp_s);
//  cout << it->a << endl;
//  cout << std::distance(v.cbegin(), it) << endl;
//
//  it = binary_find(v.cbegin(), v.cend(), 0, comp_s);
//  cout << it->a << endl;
//  cout << std::distance(v.cbegin(), it) << endl;
//
//
//  int a[] = {1, 2, 3, 4 ,5 ,6};
//  auto it2 = binary_find(&a[0], &a[5], 7); // 这个会找到数字6，然而是不存在的。
//  cout << *it2 << endl;
//  cout << std::distance(&a[0], it2) << endl;

  cout << "===================" << endl;
  int a2[] = {1, 3, 5, 7, 9, 11};
  int idx = array_binary_find(a2, 6, 8); 

  if (idx != -1) {
    cout << a2[idx] << endl;
  } else {
    cout << -1 << endl;
  }

  idx = array_binary_find(a2, 6, 3); 
  if (idx != -1) {
    cout << a2[idx] << endl;
  } else {
    cout << -1 << endl;
  }

  idx = array_binary_find(a2, 6, 1); 
  if (idx != -1) {
    cout << a2[idx] << endl;
  }else {
    cout << -1 << endl;
  }

  idx = array_binary_find(a2, 6, -2);
  if (idx != -1) {
    cout << a2[idx] << endl;
  }else {
    cout << -1 << endl;
  }

  idx = array_binary_find(a2, 6, 114);
  if (idx != -1) {
    cout << a2[idx] << endl;
  }else {
    cout << -1 << endl;
  }
}