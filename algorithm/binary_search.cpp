#include <iostream>
#include <vector>

using namespace std;

// 二分查找
// 在array中寻找target。找到返回下标，找不到返回-1；
// 要求array是有序的。
int bin_search(const vector<int> &array, int target) {
  int left = 0, right = static_cast<int>(array.size() -1);

  while (left <= right) {
    int mid = (left + right) / 2;
    if (array[mid] == target) {
      return mid;
    } else if (array[mid] > target){
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}

int main () {
  vector<int> a1 = {1, 2 ,3 ,4 ,5};
  cout << bin_search(a1, 3) << endl;

  vector<int> a2;
  cout << bin_search(a2, 100)<< endl;

  vector<int> a3 = {1, 2 ,3 ,4 ,5};
  cout << bin_search(a3, 1)<< endl;

  vector<int> a4 = {1, 2 ,3 ,4 ,5};
  cout << bin_search(a4, 5)<< endl;
}