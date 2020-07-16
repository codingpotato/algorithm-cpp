#include <doctest/doctest.h>

#include <queue>
#include <vector>

#include "tree.h"

// 637. Average of Levels in Binary Tree
class Solution {
 public:
  std::vector<double> averageOfLevels(TreeNode* root) {
    std::vector<double> result;
    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
      auto size = queue.size();
      double sum = 0;
      for (auto i = 0; i < size; ++i) {
        auto node = queue.front();
        queue.pop();
        sum += node->val;
        if (node->left) {
          queue.push(node->left);
        }
        if (node->right) {
          queue.push(node->right);
        }
      }
      result.push_back(sum / size);
    }
    return result;
  }
};

TEST_CASE("Average levels") {
  Tree tree{"3, 9, 20, null, null, 15, 7"};
  Solution s;
  REQUIRE_EQ(s.averageOfLevels(tree.root), std::vector<double>{3, 14.5, 11});
}
