#include <doctest/doctest.h>

#include "tree.h"

// 101. Symmetric Tree
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    return !root || isSymmetric(root->left, root->right);
  }

 private:
  bool isSymmetric(TreeNode* left, TreeNode* right) {
    return (!left && !right) || (left && right && left->val == right->val &&
                                 isSymmetric(left->left, right->right) &&
                                 isSymmetric(left->right, right->left));
  }
};

TEST_CASE("Symmetric Tree") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"1, 2, 2, 3, 4, 4, 3"};
    REQUIRE(s.isSymmetric(tree.root));
  }

  SUBCASE("Case 2") {
    Tree tree{"1, 2, 2, null, 3, null, 3"};
    REQUIRE_FALSE(s.isSymmetric(tree.root));
  }
}
