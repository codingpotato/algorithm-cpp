#include <doctest/doctest.h>

#include <vector>

#include "tree.h"

// 437. Path Sum III
namespace {

class Solution {
 public:
  int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    return (root->val == sum ? 1 : 0) +
           pathPartSum(root->left, sum - root->val) +
           pathPartSum(root->right, sum - root->val) +
           pathSum(root->left, sum) + pathSum(root->right, sum);
  }

 private:
  int pathPartSum(TreeNode* root, int sum) {
    if (!root) return 0;
    return pathPartSum(root->left, sum - root->val) +
           pathPartSum(root->right, sum - root->val) +
           (root->val == sum ? 1 : 0);
  }
};

}  // namespace

TEST_CASE("Path Sum III") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"10, 5, -3, 3, 2, null, 11, 3, -2, null, 1"};
    REQUIRE_EQ(s.pathSum(tree.root, 8), 3);
  }

  SUBCASE("Case 2") {
    Tree tree{"1"};
    REQUIRE_EQ(s.pathSum(tree.root, 1), 1);
  }
}
