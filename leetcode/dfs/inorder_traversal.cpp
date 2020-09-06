#include <doctest/doctest.h>

#include <stack>
#include <vector>

#include "tree.h"

// 94. Binary Tree Inorder Traversal
class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stack;
    while (root) {
      stack.push(root);
      root = root->left;
    }
    while (!stack.empty()) {
      auto node = stack.top();
      stack.pop();
      result.push_back(node->val);
      node = node->right;
      while (node) {
        stack.push(node);
        node = node->left;
      }
    }
    return result;
  }
};

TEST_CASE("Binary Tree Inorder Traversal") {
  Solution s;
  Tree tree{"1, null, 2, 3"};
  REQUIRE_EQ(s.inorderTraversal(tree.root), std::vector<int>{1, 3, 2});
}
