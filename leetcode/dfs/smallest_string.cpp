#include <doctest/doctest.h>

#include <iostream>
#include <string>

#include "tree.h"

// 988. Smallest String Starting From Leaf
class Solution {
 public:
  std::string smallestFromLeaf(TreeNode* root) {
    std::string result;
    if (root) {
      visit(root, "", result);
    }
    return result;
  }

 private:
  void visit(TreeNode* root, std::string current, std::string& result) {
    current = std::string{static_cast<char>('a' + root->val)} + current;
    if (!root->left && !root->right) {
      if (result.empty() || current < result) {
        result = current;
      }
    } else {
      if (root->left) visit(root->left, current, result);
      if (root->right) visit(root->right, current, result);
    }
  }
};

TEST_CASE("Smallest String Starting From Leaf") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"0, 1, 2, 3, 4, 3, 4"};
    REQUIRE_EQ(s.smallestFromLeaf(tree.root), "dba");
  }

  SUBCASE("Case 2") {
    Tree tree{"25, 1, 3, 1, 3, 0, 2"};
    REQUIRE_EQ(s.smallestFromLeaf(tree.root), "adz");
  }

  SUBCASE("Case 3") {
    Tree tree{"2, 2, 1, null, 1, 0, null, 0"};
    REQUIRE_EQ(s.smallestFromLeaf(tree.root), "abc");
  }
}
