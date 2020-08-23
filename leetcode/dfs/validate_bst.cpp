#include <doctest/doctest.h>

#include <climits>

#include "tree.h"

// 98. Validate Binary Search Tree
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return is_valid_bst(root, false, 0, false, 0);
  }

 private:
  bool is_valid_bst(TreeNode* root, bool has_min, int min, bool has_max,
                    int max) {
    return !root ||
           ((!has_min || min < root->val) && (!has_max || max > root->val) &&
            is_valid_bst(root->left, has_min, min, true, root->val) &&
            is_valid_bst(root->right, true, root->val, has_max, max));
  }
};

TEST_CASE("Validate Binary Search Tree") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"2, 1, 3"};
    REQUIRE(s.isValidBST(tree.root));
  }

  SUBCASE("Case 2") {
    Tree tree{"5, 1, 4, null, null, 3, 6"};
    REQUIRE_FALSE(s.isValidBST(tree.root));
  }

  SUBCASE("Case 3") {
    Tree tree{"3, 1, 5, 0, 2, 4, 6, null, null, null, 3"};
    REQUIRE_FALSE(s.isValidBST(tree.root));
  }

  SUBCASE("Empty tree") {
    Tree tree{""};
    REQUIRE(s.isValidBST(tree.root));
  }

  SUBCASE("Max int") {
    Tree tree{"2147483647, 2147483647"};
    REQUIRE_FALSE(s.isValidBST(tree.root));
  }
}
