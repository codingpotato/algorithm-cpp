#include <doctest/doctest.h>

#include "tree.h"

// 110. Balanced Binary Tree
namespace {

class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    auto banlanced = is_balanced(root);
    return banlanced.first;
  }

 private:
  std::pair<bool, int> is_balanced(TreeNode* root) {
    if (!root) return {true, 0};
    auto [left_b, left_d] = is_balanced(root->left);
    auto [right_b, right_d] = is_balanced(root->right);
    return {left_b && right_b && std::abs(right_d - left_d) <= 1,
            std::max(left_d, right_d) + 1};
  }
};

}  // namespace

TEST_CASE("Balanced Binary Tree") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"3, 9, 20, null, null, 15, 7"};
    REQUIRE(s.isBalanced(tree.root));
  }

  SUBCASE("Case 2") {
    Tree tree{"1, 2, 2, 3, 3, null, null, 4, 4"};
    REQUIRE_FALSE(s.isBalanced(tree.root));
  }

  SUBCASE("Case 3") {
    Tree tree{"1, 2, 3, 4, 5, null, 6, 7, null, null, null, null, 8"};
    REQUIRE_FALSE(s.isBalanced(tree.root));
  }
}
