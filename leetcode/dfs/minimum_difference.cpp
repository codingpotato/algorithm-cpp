#include <doctest/doctest.h>

#include <climits>

#include "tree.h"

// 530. Minimum Absolute Difference in BST
namespace {

class Solution {
 public:
  int getMinimumDifference(TreeNode* root) {
    inorder(root);
    return min_diff;
  }

 private:
  void inorder(TreeNode* root) {
    if (root->left) inorder(root->left);
    if (!previous) {
      previous = root;
    } else {
      min_diff = std::min(min_diff, root->val - previous->val);
      previous = root;
    }
    if (root->right) inorder(root->right);
  }

  int min_diff = INT_MAX;
  TreeNode* previous = nullptr;
};

}  // namespace

TEST_CASE("Minimum Absolute Difference in BST") {
  Solution s;
  Tree tree{"1, null, 3, 2"};
  REQUIRE_EQ(s.getMinimumDifference(tree.root), 1);
}
