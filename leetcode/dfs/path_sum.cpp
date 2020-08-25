#include <doctest/doctest.h>

#include <iostream>

#include "tree.h"

// 112. Path Sum
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    return (root && !root->left && !root->right && sum == root->val) ||
           (root && root->left && hasPathSum(root->left, sum - root->val)) ||
           (root && root->right && hasPathSum(root->right, sum - root->val));
  }
};

TEST_CASE("Path sum") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{
        "5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, null, null, 1"};
    REQUIRE(s.hasPathSum(tree.root, 22));
  }

  SUBCASE("Case 2") {
    Tree tree{"1, 2, 3"};
    REQUIRE_FALSE(s.hasPathSum(tree.root, 22));
  }

  SUBCASE("Empty tree") {
    Tree tree{""};
    REQUIRE_FALSE(s.hasPathSum(tree.root, 0));
  }
}
