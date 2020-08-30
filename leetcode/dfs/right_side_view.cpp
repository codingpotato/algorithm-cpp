#include <doctest/doctest.h>

#include <vector>

#include "tree.h"

// 199. Binary Tree Right Side View
class Solution {
 public:
  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    if (root) {
      rightSideView(root, 1, 0, result);
    }
    return result;
  }

 private:
  int rightSideView(TreeNode* root, int depth, int right_depth,
                    std::vector<int>& result) {
    if (depth > right_depth) {
      result.push_back(root->val);
    }
    auto right_child_depth = 0;
    if (root->right) {
      right_child_depth =
          rightSideView(root->right, depth + 1, right_depth, result);
    }
    auto left_child_depth = 0;
    if (root->left) {
      left_child_depth =
          rightSideView(root->left, depth + 1,
                        std::max(right_depth, right_child_depth), result);
    }
    return std::max(depth, std::max(left_child_depth, right_child_depth));
  }
};

TEST_CASE("Binary Tree Right Side View") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"1, 2, 3, null, 5, null, 4"};
    REQUIRE_EQ(s.rightSideView(tree.root), std::vector<int>{1, 3, 4});
  }

  SUBCASE("Case 2") {
    Tree tree{"1, 2"};
    REQUIRE_EQ(s.rightSideView(tree.root), std::vector<int>{1, 2});
  }
}
