#include <doctest/doctest.h>

#include <queue>

#include "tree.h"

// 662. Maximum Width of Binary Tree
class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    struct Info {
      Info(TreeNode* node, int index) : node{node}, index{index} {}
      TreeNode* node;
      long index;
    };
    std::queue<Info> queue;
    queue.emplace(root, 0);
    auto max_width = 0;
    while (!queue.empty()) {
      int size = queue.size();
      long left = 0;
      long right = 0;
      for (auto i = 0; i < size; ++i) {
        auto [node, index] = queue.front();
        queue.pop();
        if (i == 0) left = index;
        if (i == size - 1) right = index;
        if (node->left) queue.emplace(node->left, index * 2);
        if (node->right) queue.emplace(node->right, index * 2 + 1);
      }
      max_width = std::max(max_width, static_cast<int>(right - left + 1));
    }
    return max_width;
  }
};

TEST_CASE("Maximum Width of Binary Tree") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"1, 3, 2, 5, 3, null, 9"};
    REQUIRE_EQ(s.widthOfBinaryTree(tree.root), 4);
  }

  SUBCASE("Case 2") {
    Tree tree{"1, 3, null, 5, 3"};
    REQUIRE_EQ(s.widthOfBinaryTree(tree.root), 2);
  }

  SUBCASE("Case 3") {
    Tree tree{"1, 3, 2, 5"};
    REQUIRE_EQ(s.widthOfBinaryTree(tree.root), 2);
  }

  SUBCASE("Case 4") {
    Tree tree{"1, 3, 2, 5, null, null, 9, 6, null, null, 7"};
    REQUIRE_EQ(s.widthOfBinaryTree(tree.root), 8);
  }

  SUBCASE("Case 5") {
    Tree tree{
        "0, 0, 0, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, "
        "0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, "
        "null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, "
        "null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, "
        "0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, "
        "0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, "
        "null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, "
        "null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, "
        "0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, "
        "0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, "
        "null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, "
        "null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, "
        "0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, "
        "0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, "
        "null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, "
        "null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, "
        "0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, "
        "0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null"};
    REQUIRE_EQ(s.widthOfBinaryTree(tree.root), 2);
  }
}
