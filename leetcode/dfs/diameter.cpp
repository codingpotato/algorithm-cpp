#include <doctest/doctest.h>

#include <climits>
#include <utility>

#include "tree.h"

// 543. Diameter of Binary Tree
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    auto [diameter, max_to_leaf] = diameter_node(root);
    return diameter - 1;
  }

 private:
  std::pair<int, int> diameter_node(TreeNode* node) {
    if (!node) {
      return {1, 0};
    }
    auto [d_l, l] = diameter_node(node->left);
    auto [d_r, r] = diameter_node(node->right);
    auto diameter = std::max(std::max(d_l, d_r), l + r + 1);
    return {diameter, std::max(l, r) + 1};
  }
};

TEST_CASE("Diameter of binary tree") {
  Solution s;

  SUBCASE("Normal case") {
    Tree tree{"1, 2, 3, 4, 5"};
    REQUIRE_EQ(s.diameterOfBinaryTree(tree.root), 3);
  }

  SUBCASE("Empty tree") {
    Tree tree{""};
    REQUIRE_EQ(s.diameterOfBinaryTree(tree.root), 0);
  }
}
