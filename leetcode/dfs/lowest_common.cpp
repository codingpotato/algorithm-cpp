#include <doctest/doctest.h>

#include "tree.h"

// 236. Lowest Common Ancestor of a Binary Tree
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    if (root == p) return root;
    if (root == q) return root;
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    if (left) return left;
    return right;
  }
};

TEST_CASE("Lowest Common Ancestor of a Binary Tree") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"3, 5, 1, 6, 2, 0, 8, null, null, 7, 4"};
    auto p = tree.root->left;
    auto q = tree.root->right;
    auto node = s.lowestCommonAncestor(tree.root, p, q);
    REQUIRE_EQ(node->val, 3);
  }

  SUBCASE("Case 2") {
    Tree tree{"3, 5, 1, 6, 2, 0, 8, null, null, 7, 4"};
    auto p = tree.root->left;
    auto q = tree.root->left->right->right;
    auto node = s.lowestCommonAncestor(tree.root, p, q);
    REQUIRE_EQ(node->val, 5);
  }
}
