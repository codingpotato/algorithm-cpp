#include <doctest/doctest.h>

#include <vector>

#include "tree.h"

// 113. Path Sum II
namespace {

class Solution {
 public:
  using Result = std::vector<std::vector<int>>;

  Result pathSum(TreeNode* root, int sum) {
    Result result;
    if (!root) return result;
    std::vector<int> current;
    pathSum(root, sum, current, result);
    return result;
  }

 private:
  void pathSum(TreeNode* root, int sum, std::vector<int>& current,
               Result& result) {
    if (!root->left && !root->right) {
      if (root->val == sum) {
        current.push_back(root->val);
        result.push_back(current);
        current.pop_back();
      }
    } else {
      if (root->left) {
        current.push_back(root->val);
        pathSum(root->left, sum - root->val, current, result);
        current.pop_back();
      }
      if (root->right) {
        current.push_back(root->val);
        pathSum(root->right, sum - root->val, current, result);
        current.pop_back();
      }
    }
  }
};

}  // namespace

TEST_CASE("Path sum") {
  Solution s;
  Tree tree{"5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, null, 5, 1"};
  REQUIRE_EQ(s.pathSum(tree.root, 22),
             Solution::Result{{5, 4, 11, 2}, {5, 8, 4, 5}});
}
