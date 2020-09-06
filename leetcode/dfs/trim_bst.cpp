#include <doctest/doctest.h>

#include "tree.h"

// 669. Trim a Binary Search Tree
class Solution {
 public:
  TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (!root) return nullptr;
    if (root->val < L) return trimBST(root->right, L, R);
    if (root->val > R) return trimBST(root->left, L, R);
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
  }
};

TEST_CASE("Trim a Binary Search Tree") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"1, 0, 2"};
    auto root = s.trimBST(tree.root, 1, 2);
    Tree expected{"1, null, 2"};
    REQUIRE(is_same(root, expected.root));
  }

  SUBCASE("Case 2") {
    Tree tree{"3, 0, 4, null, 2, null, null, 1"};
    auto root = s.trimBST(tree.root, 1, 3);
    Tree expected{"3, 2, null, 1"};
    REQUIRE(is_same(root, expected.root));
  }
}
