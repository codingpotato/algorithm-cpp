#include <doctest/doctest.h>

#include "tree.h"

// 450. Delete Node in a BST
class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      if (!root->left) return root->right;
      if (!root->right) return root->left;
      auto right = root->right;
      while (right->left) {
        right = right->left;
      }
      root->val = right->val;
      root->right = deleteNode(root->right, right->val);
    }
    return root;
  }
};

TEST_CASE("Delete Node in a BST") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"5, 3, 6, 2, 4, null, 7"};
    auto root = s.deleteNode(tree.root, 3);
    Tree expected{"5, 4, 6, 2, null, null, 7"};
    REQUIRE(is_same(root, expected.root));
  }

  SUBCASE("Case 2") {
    Tree tree{"5, 3, 6, 2, 4, null, 7"};
    auto root = s.deleteNode(tree.root, 0);
    REQUIRE(is_same(root, tree.root));
  }

  SUBCASE("Case 3") {
    Tree tree{""};
    auto root = s.deleteNode(tree.root, 0);
    REQUIRE(is_same(root, tree.root));
  }
}
