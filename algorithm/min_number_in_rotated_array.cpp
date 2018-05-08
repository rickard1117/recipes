#include <iostream>
#include <vector>

using namespace std;

int min(const vector<int> &arr) {
  size_t left = 0, right = arr.size() - 1, mid = 0;
  while (left <= right) {
    mid = (left + right) / 2;
    if (arr[mid] > arr[left] && arr[mid] > arr[right]) {
      left = mid + 1;
    } else if (arr[mid] < arr[left] && arr[mid] < arr[right]) {
      right = mid - 1;
    } else {
      return (int)left;
    }
  }
  return (int)mid;
}

int main() {
  vector<int> a = {3,4,5,1,2};
  cout << min(a) << endl;

  a = {1,2,3,4,5};
  cout << min(a) << endl;


  a = {5,6,7,8,77,565,1,2,3,4};
  cout << min(a) << endl;

  return 0;
}