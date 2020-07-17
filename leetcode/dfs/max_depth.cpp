#include <doctest/doctest.h>

#include "tree.h"

// 104. Maximum Depth of Binary Tree
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    return !root ? 0
                 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

TEST_CASE("Maximum depth of binary tree") {
  Solution s;

  Tree tree{"3, 9, 20, null, null, 15, 7"};
  REQUIRE_EQ(s.maxDepth(tree.root), 3);
}
