#include <doctest/doctest.h>

#include "tree.h"

// 617. Merge Two Binary Trees
class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) {
      return nullptr;
    }
    auto val = t1 ? t1->val : 0;
    val += t2 ? t2->val : 0;
    auto node = new TreeNode{val};
    node->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
    node->right =
        mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
    return node;
  }
};

TEST_CASE("Merge two binary tree") {
  Solution s;

  Tree tree1{"1, 3, 2, 5"};
  Tree tree2{"2, 1, 3, null, 4, null, 7"};
  auto root = s.mergeTrees(tree1.root, tree2.root);

  REQUIRE_EQ(root->val, 3);
  REQUIRE_EQ(root->left->val, 4);
  REQUIRE_EQ(root->right->val, 5);
  REQUIRE_EQ(root->left->left->val, 5);
  REQUIRE_EQ(root->left->right->val, 4);
  REQUIRE_EQ(root->right->left, nullptr);
  REQUIRE_EQ(root->right->right->val, 7);
}
