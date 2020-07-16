#include <doctest/doctest.h>

#include <queue>
#include <vector>

#include "tree.h"

// 107. Binary Tree Level Order Traversal II
class Solution {
 public:
  std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) {
      return result;
    }
    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
      auto size = queue.size();
      std::vector<int> row;
      for (auto i = 0; i < size; ++i) {
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
    int left = 0;
    int right = result.size() - 1;
    while (left < right) {
      std::swap(result[left++], result[right--]);
    }
    return result;
  }
};

TEST_CASE("Binary tree level order traversal") {
  Tree tree{"3, 9, 20, null, null, 15, 7"};
  Solution s;
  REQUIRE_EQ(s.levelOrderBottom(tree.root),
             std::vector<std::vector<int>>{std::vector<int>{15, 7},
                                           std::vector<int>{9, 20},
                                           std::vector<int>{3}});
}
