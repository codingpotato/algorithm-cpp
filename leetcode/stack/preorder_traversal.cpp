#include <doctest/doctest.h>

#include <stack>
#include <vector>

#include "tree.h"

// 144. Binary Tree Preorder Traversal
class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stack;
    if (root) stack.push(root);
    while (!stack.empty()) {
      auto node = stack.top();
      stack.pop();
      result.push_back(node->val);
      if (node->right) stack.push(node->right);
      if (node->left) stack.push(node->left);
    }
    return result;
  }
};

TEST_CASE("Binary Tree Preorder Traversal") {
  Solution s;
  Tree tree{"1, null, 2, 3"};
  REQUIRE_EQ(s.preorderTraversal(tree.root), std::vector<int>{1, 2, 3});
}
