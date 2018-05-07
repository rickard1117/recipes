#include <iostream>
#include <queue>
#include <memory>
// 和二叉树相关的一些算法的实现

using namespace std;


struct Node {
  explicit Node(int v): left(nullptr), right(nullptr), val(v) {

  }

  const Node *add_left(int v) {
    left = make_unique<Node>(v);
    return left.get();
  }

  const Node *add_right(int v) {
    right = make_unique<Node>(v);
    return right.get();
  }

  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
  int val;
};


static std::unique_ptr<Node> create_binary_tree(int root_val) {
  return make_unique<Node>(root_val);
}

// 根据先序和中序遍历的结果来重建一棵二叉树
int main () {
  auto root = create_binary_tree(0);
  auto left = root->add_left(1);
  auto right = root->add_right(2);
  cout << root->val;
  cout << left->val;
  cout << right->val;

  return 0;
}