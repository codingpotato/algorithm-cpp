#include <doctest/doctest.h>

#include <algorithm>

#include "tree.h"

// 111. Minimum Depth of Binary Tree
class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    if (!root->left && !root->right) {
      return 1;
    }
    if (!root->left) {
      return minDepth(root->right) + 1;
    }
    if (!root->right) {
      return minDepth(root->left) + 1;
    }
    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
  }
};

TEST_CASE("Minimum depth") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"3, 9, 20, null, null, 15, 7"};
    REQUIRE_EQ(s.minDepth(tree.root), 2);
  }

  SUBCASE("Case 2") {
    Tree tree{"1, 2"};
    REQUIRE_EQ(s.minDepth(tree.root), 2);
  }
}
