#include <doctest/doctest.h>

#include "tree.h"

// 572. Subtree of Another Tree
class Solution {
 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    return isSameTree(s, t) ||
           (s && (isSubtree(s->left, t) || isSubtree(s->right, t)));
  }

 private:
  bool isSameTree(TreeNode* s, TreeNode* t) {
    return (!s && !t) ||
           (s && t && s->val == t->val && isSameTree(s->left, t->left) &&
            isSameTree(s->right, t->right));
  }
};

TEST_CASE("Subtree") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree1{"3, 4, 5, 1, 2"};
    Tree tree2{"4, 1, 2"};
    REQUIRE(s.isSubtree(tree1.root, tree2.root));
  }

  SUBCASE("Case 2") {
    Tree tree1{"3, 4, 5, 1, 2, null, null, null, null, 0"};
    Tree tree2{"4, 1, 2"};
    REQUIRE_FALSE(s.isSubtree(tree1.root, tree2.root));
  }
}
