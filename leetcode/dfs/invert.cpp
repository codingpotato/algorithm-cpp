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

  REQUIRE_EQ(root->val, 4);
  REQUIRE_EQ(root->left->val, 7);
  REQUIRE_EQ(root->right->val, 2);
  REQUIRE_EQ(root->left->left->val, 9);
  REQUIRE_EQ(root->left->right->val, 6);
  REQUIRE_EQ(root->right->left->val, 3);
  REQUIRE_EQ(root->right->right->val, 1);
}
