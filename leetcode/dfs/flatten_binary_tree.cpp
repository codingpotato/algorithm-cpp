#include <doctest/doctest.h>

#include "tree.h"

// 114. Flatten Binary Tree to Linked List
class Solution {
 public:
  void flatten(TreeNode* root) { flatten_node(root); }

 private:
  TreeNode* flatten_node(TreeNode* root) {
    if (!root) return nullptr;
    auto left = root->left;
    auto right = root->right;
    root->left = nullptr;
    auto left_tail = flatten_node(left);
    if (left_tail) {
      root->right = left;
      left_tail->right = right;
    } else {
      root->right = right;
    }
    auto right_tail = flatten_node(right);
    return right_tail ? right_tail : (left_tail ? left_tail : root);
  }
};

TEST_CASE("Flatten Binary Tree to Linked List") {
  Solution s;
  Tree tree{"1, 2, 5, 3, 4, null, 6"};
  s.flatten(tree.root);
  Tree expected{"1, null, 2, null, 3, null, 4, null, 5, null, 6"};
  REQUIRE(is_same(tree.root, expected.root));
}