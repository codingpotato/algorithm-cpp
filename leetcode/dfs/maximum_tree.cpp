#include <doctest/doctest.h>

#include <vector>

#include "tree.h"

// 654. Maximum Binary Tree
class Solution {
 public:
  TreeNode* constructMaximumBinaryTree(const std::vector<int>& nums) {
    return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode* constructMaximumBinaryTree(const std::vector<int>& nums, int left,
                                       int right) {
    if (left > right) return nullptr;
    auto index = left;
    auto max = nums[index];
    for (auto i = left + 1; i <= right; ++i) {
      if (nums[i] > max) {
        max = nums[i];
        index = i;
      }
    }
    auto node = new TreeNode(max);
    node->left = constructMaximumBinaryTree(nums, left, index - 1);
    node->right = constructMaximumBinaryTree(nums, index + 1, right);
    return node;
  }
};

TEST_CASE("Maximum Binary Tree") {
  Solution s;
  auto root = s.constructMaximumBinaryTree({3, 2, 1, 6, 0, 5});

  REQUIRE_EQ(root->val, 6);
  REQUIRE_EQ(root->left->val, 3);
  REQUIRE_EQ(root->right->val, 5);
  REQUIRE_EQ(root->left->right->val, 2);
  REQUIRE_EQ(root->left->right->right->val, 1);
  REQUIRE_EQ(root->right->val, 5);
  REQUIRE_EQ(root->right->left->val, 0);
}
