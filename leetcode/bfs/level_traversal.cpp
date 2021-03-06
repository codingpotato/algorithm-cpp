#include <doctest/doctest.h>

#include <queue>
#include <vector>

#include "tree.h"

// 102. Binary Tree Level Order Traversal

namespace {

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) {
      return result;
    }
    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
      auto size = queue.size();
      std::vector<int> row;
      for (size_t i = 0; i < size; ++i) {
        auto node = queue.front();
        row.push_back(node->val);
        queue.pop();
        if (node->left) {
          queue.push(node->left);
        }
        if (node->right) {
          queue.push(node->right);
        }
      }
      result.push_back(row);
    }
    return result;
  }
};

}  // namespace

TEST_CASE("Binary tree level order traversal") {
  Tree tree{"3, 9, 20, null, null, 15, 7"};
  Solution s;
  REQUIRE_EQ(s.levelOrder(tree.root),
             std::vector<std::vector<int>>{{3}, {9, 20}, {15, 7}});
}
