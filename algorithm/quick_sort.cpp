#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &array, size_t left, size_t right) {
  int tmp = array[left];
  array[left] = array[right];
  array[right] = tmp;
}

// 从数组中选出一个target,把数组划分成两部分，左边部分小于某个数，右边部分大于某个数。
// 并返回target所在下标。
size_t Partition(vector<int> &array, size_t start, size_t end) {
  auto target = array[start];
  
  for (auto i = start + 1; i <= end; ++i) {
    if (array[i] < target) {
      swap(array, start, i);
      ++start;
    }
  }  
  return start;
}


int main() {
  vector<int> v = {1,2,3};
  cout << Partition(v, 0, 2) << endl;

  vector<int> v1 = {2,1,3,4};
  cout << Partition(v1, 0, 3) << endl;

  vector<int> v2 = {5,4,3,2,1};
  cout << Partition(v2, 0, 4) << endl;
  
  vector<int> v3 = {3,4,3,2,1,0};
  cout << Partition(v3, 0, 5) << endl;
  for (auto i : v3) {
    cout << i;
  }
}
