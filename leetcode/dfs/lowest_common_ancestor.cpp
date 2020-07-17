#include <doctest/doctest.h>

#include "tree.h"

// 235. Lowest Common Ancestor of a Binary Search Tree
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
      return root;
    }
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if (left && right) {
      return root;
    }
    return left ? left : right;
  }
};

TEST_CASE("Lowest common ancestor of binary tree") {
  Solution s;

  Tree tree{"6, 2, 8, 0, 4, 7, 9, null, null, 3, 5"};
  REQUIRE_EQ(
      s.lowestCommonAncestor(tree.root, tree.root->left, tree.root->right),
      tree.root);
  REQUIRE_EQ(s.lowestCommonAncestor(tree.root, tree.root->left,
                                    tree.root->left->right->right),
             tree.root->left);
}
