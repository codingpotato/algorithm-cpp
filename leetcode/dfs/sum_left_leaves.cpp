#include <doctest/doctest.h>

#include "tree.h"

// 404. Sum of Left Leaves
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) { return sumOfLeftLeaves(root, true); }

 private:
  int sumOfLeftLeaves(TreeNode* root, bool left) {
    if (!root) return 0;
    if (left && !root->left && !root->right) return root->val;
    return sumOfLeftLeaves(root->left, true) +
           sumOfLeftLeaves(root->right, false);
  }
};

TEST_CASE("Sum of Left Leaves") {
  Solution s;
  Tree tree{"3, 9, 20, null, null, 15, 7"};
  REQUIRE_EQ(s.sumOfLeftLeaves(tree.root), 24);
}
