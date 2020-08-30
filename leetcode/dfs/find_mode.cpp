#include <doctest/doctest.h>

#include <vector>

#include "tree.h"

// 501. Find Mode in Binary Search Tree
class Solution {
 public:
  std::vector<int> findMode(TreeNode* root) {
    std::vector<int> result;
    auto result_count = 0;
    auto current_count = 0;
    visit(root, result_count, current_count, result);
    if (current_count < result_count) {
      result.pop_back();
    }
    return result;
  }

 private:
  void visit(TreeNode* root, int& result_count, int& current_count,
             std::vector<int>& result) {
    if (!root) return;
    visit(root->left, result_count, current_count, result);
    if (result.empty()) {
      result.push_back(root->val);
      result_count = 1;
      current_count = 1;
    } else {
      if (root->val == result.back()) {
        ++current_count;
        if (current_count > result_count) {
          result.clear();
          result.push_back(root->val);
          result_count = current_count;
        }
      } else {
        if (current_count < result_count) {
          result.pop_back();
        }
        result.push_back(root->val);
        current_count = 1;
      }
    }
    visit(root->right, result_count, current_count, result);
  }
};

TEST_CASE("Find Mode in Binary Search Tree") {
  Solution s;
  Tree tree{"1, null, 2, 2"};
  REQUIRE_EQ(tree.root->val, 1);
  REQUIRE_EQ(tree.root->right->val, 2);
  REQUIRE_EQ(tree.root->right->left->val, 2);
  REQUIRE_EQ(s.findMode(tree.root), std::vector<int>{2});
}
