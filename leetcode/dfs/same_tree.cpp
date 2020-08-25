#include <doctest/doctest.h>

#include "tree.h"

// 100. Same Tree
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    return (!p && !q) ||
           (p && q && p->val == q->val && isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right));
  }
};

TEST_CASE("Same tree") {
  Solution s;

  SUBCASE("case 1") {
    Tree tree1{"1, 2, 3"};
    Tree tree2{"1, 2, 3"};
    REQUIRE(s.isSameTree(tree1.root, tree2.root));
  }

  SUBCASE("case 2") {
    Tree tree1{"1, 2"};
    Tree tree2{"1, null, 2"};
    REQUIRE_FALSE(s.isSameTree(tree1.root, tree2.root));
  }

  SUBCASE("case 3") {
    Tree tree1{"1, 2, 1"};
    Tree tree2{"1, 1, 2"};
    REQUIRE_FALSE(s.isSameTree(tree1.root, tree2.root));
  }
}
