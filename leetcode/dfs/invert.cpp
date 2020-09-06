#include <doctest/doctest.h>

#include "tree.h"

// 226. Invert Binary Tree
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    auto left = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(left);
    return root;
  }
};

TEST_CASE("Invert binary tree") {
  Solution s;

  Tree tree{"4, 2, 7, 1, 3, 6, 9"};
  auto root = s.invertTree(tree.root);
  Tree expected{"4, 7, 2, 9, 6, 3, 1"};
  REQUIRE(is_same(root, expected.root));
}
