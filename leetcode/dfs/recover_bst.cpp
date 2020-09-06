#include <doctest/doctest.h>

#include "tree.h"

// 99. Recover Binary Search Tree

namespace {

class Solution {
 public:
  void recoverTree(TreeNode* root) {
    inorder(root);
    std::swap(first->val, second->val);
  }

 private:
  void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    if (!previous) {
      previous = root;
    } else {
      if (previous->val > root->val) {
        if (!first) {
          first = previous;
        }
        second = root;
      }
      previous = root;
    }
    inorder(root->right);
  }

  TreeNode* previous = nullptr;
  TreeNode* first = nullptr;
  TreeNode* second = nullptr;
};

}  // namespace

TEST_CASE("Recover Binary Search Tree") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"1, 3, null, null, 2"};
    s.recoverTree(tree.root);
    Tree expected{"3, 1, null, null, 2"};
    REQUIRE(is_same(tree.root, expected.root));
  }

  SUBCASE("Case 2") {
    Tree tree{"3, 1, 4, null, null, 2"};
    s.recoverTree(tree.root);
    Tree expected{"2, 1, 4, null, null, 3"};
    REQUIRE(is_same(tree.root, expected.root));
  }
}
