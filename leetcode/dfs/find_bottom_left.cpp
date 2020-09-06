#include <doctest/doctest.h>

#include "tree.h"

// 513. Find Bottom Left Tree Value
class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    Info info{-1, 0, 0};
    visit(root, 0, 0, info);
    return info.value;
  }

 private:
  struct Info {
    int depth;
    int index;
    int value;
  };

  void visit(TreeNode* root, int depth, int index, Info& info) {
    if (root->left) visit(root->left, depth + 1, index - 1, info);
    if (root->right) visit(root->right, depth + 1, index + 1, info);
    if (depth > info.depth || (depth == info.depth && index < info.index)) {
      info.depth = depth;
      info.index = index;
      info.value = root->val;
    }
  }
};

TEST_CASE("Find Bottom Left Tree Value") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"2, 1, 3"};
    REQUIRE(s.findBottomLeftValue(tree.root), 1);
  }

  SUBCASE("Case 2") {
    Tree tree{"1, 2, 3, 4, null, 5, 6, null, null, 7"};
    REQUIRE(s.findBottomLeftValue(tree.root), 7);
  }
}
