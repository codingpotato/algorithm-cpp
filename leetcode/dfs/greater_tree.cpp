#include <doctest/doctest.h>

#include "tree.h"

// 538. Convert BST to Greater Tree
class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    visit(root, 0);
    return root;
  }

 private:
  int visit(TreeNode* root, int greater_sum) {
    if (!root) return 0;
    auto right_sum = visit(root->right, greater_sum);
    auto sum = right_sum + root->val;
    root->val += greater_sum + right_sum;
    return sum + visit(root->left, root->val);
  }
};

TEST_CASE("Convert BST to Greater Tree") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"5, 2, 13"};
    auto root = s.convertBST(tree.root);
    Tree expected{"18, 20, 13"};
    REQUIRE(is_same(root, expected.root));
  }

  SUBCASE("Case 2") {
    Tree tree{"5, 3, 6, 2, 4, null, null, 1"};
    auto root = s.convertBST(tree.root);
    Tree expected{"11, 18, 6, 20, 15, null, null, 21"};
    REQUIRE(is_same(root, expected.root));
  }
}
