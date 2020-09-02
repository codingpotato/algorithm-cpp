#include <doctest/doctest.h>

#include "tree.h"

// 938. Range Sum of BST
class Solution {
 public:
  int rangeSumBST(TreeNode* root, int L, int R) {
    auto sum = 0;
    visit(root, L, R, sum);
    return sum;
  }

 private:
  void visit(TreeNode* root, int L, int R, int& sum) {
    if (!root) return;
    if (root->val >= L && root->val <= R) {
      sum += root->val;
      visit(root->left, L, R, sum);
      visit(root->right, L, R, sum);
    } else if (root->val < L) {
      visit(root->right, L, R, sum);
    } else {
      visit(root->left, L, R, sum);
    }
  }
};

TEST_CASE("Range Sum of BST") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"10, 5, 15, 3, 7, null, 18"};
    REQUIRE_EQ(s.rangeSumBST(tree.root, 7, 15), 32);
  }

  SUBCASE("Case 2") {
    Tree tree{"10, 5, 15, 3, 7, 13, 18, 1, null, 6"};
    REQUIRE_EQ(s.rangeSumBST(tree.root, 6, 10), 23);
  }
}
