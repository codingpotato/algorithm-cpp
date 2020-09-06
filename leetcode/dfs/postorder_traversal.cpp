#include <doctest/doctest.h>

#include <stack>
#include <vector>

#include "tree.h"

// 145. Binary Tree Postorder Traversal
namespace {

class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;
    std::stack<Info> stack;
    stack.emplace(root, traversal);
    while (!stack.empty()) {
      auto info = stack.top();
      stack.pop();
      if (info.phase == traversal) {
        stack.emplace(info.node, print);
        if (info.node->right) stack.emplace(info.node->right, traversal);
        if (info.node->left) stack.emplace(info.node->left, traversal);
      } else {
        result.push_back(info.node->val);
      }
    }
    return result;
  }

 private:
  enum Phase { traversal, print };

  struct Info {
    Info(TreeNode* node, Phase phase) : node{node}, phase{phase} {}

    TreeNode* node;
    Phase phase;
  };
};

}  // namespace

TEST_CASE("Binary Tree Postorder Traversal") {
  Solution s;
  Tree tree{"1, null, 2, 3"};
  REQUIRE_EQ(s.postorderTraversal(tree.root), std::vector<int>{3, 2, 1});
}
