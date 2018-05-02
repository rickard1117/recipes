#include <string>
#include <iostream>

using namespace std;


// 将str中所有的c替换为target(要求target.size() != 0)
void ReplaceBlank(string &str, char c, const string &target) {
  auto blank_n = 0;
  for (auto it = str.cbegin(); it != str.cend(); ++it) {
    if (*it == c) {
      blank_n++;
    }
  }

  if (blank_n == 0) return;

  size_t target_size = target.size();
  size_t left = str.size() - 1;
  size_t right = left + blank_n * (target_size - 1);

  str.resize(right + 1);

  while (left > 0) {
    if (str[left] == c) {
      for(auto i =  target_size; i > 0; --i) {
        str[right] = target[i - 1];
        right --;
      }
      left--;
    } else {
      str[right] = str[left];
      right--;
      left--;
    }
  }
}

int main() {
  string t1 = "abcdefg";
  ReplaceBlank(t1, 'k', "kkkk");
  cout << "t1 " << t1 << endl;


  string t2 = "abcdefg";
  ReplaceBlank(t2, 'g', "kkkk");
  cout << "t2 " << t2 << endl;

  string t3 = "";
  ReplaceBlank(t3, 'g', "kkkk");
  cout << "t3 " << t3 << endl;

  string t4 = "asdf asdfs dfwe";
  ReplaceBlank(t4, ' ', "  ");
  cout << "t4 " << t4 << endl;
}