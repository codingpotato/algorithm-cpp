#include <doctest/doctest.h>

#include "tree.h"

// 897. Increasing Order Search Tree
class Solution {
 public:
  TreeNode* increasingBST(TreeNode* root) {
    visit(root);
    return new_root;
  }

 private:
  void visit(TreeNode* root) {
    if (root->left) visit(root->left);
    if (!new_root) {
      new_root = root;
      prev = root;
    } else {
      prev->left = nullptr;
      prev->right = root;
      prev = root;
    }
    if (root->right) visit(root->right);
  }

  TreeNode* new_root = nullptr;
  TreeNode* prev = nullptr;
};

TEST_CASE("Increasing Order Search Tree") {
  Solution s;
  Tree tree{"5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9"};
  auto root = s.increasingBST(tree.root);
  Tree expected{
      "1, null, 2, null, 3, null, 4, null, 5, null, 6, null, 7, null, 8, null, "
      "9"};
  REQUIRE(is_same(root, expected.root));
}
