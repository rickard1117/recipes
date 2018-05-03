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
int Partition(vector<int> &array, size_t start, size_t end) {
  auto target = array[start];

  while (start < end) {
    if (array[end] < target) {
      swap(array, start, end);
      start =+ 1;
    } else {
      end -= 1;
    }
  }

  return static_cast<int>(start);
}


int main() {
  vector<int> v = {1,2,3};
  cout << Partition(v, 0, 2) << endl;

  vector<int> v1 = {2,1,3,4};
  cout << Partition(v1, 0, 3) << endl;

  vector<int> v2 = {5,4,3,2,1};
  cout << Partition(v2, 0, 4) << endl;

}