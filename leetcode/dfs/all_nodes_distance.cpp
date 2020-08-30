#include <doctest/doctest.h>

#include <vector>

#include "tree.h"

// 863. All Nodes Distance K in Binary Tree
class Solution {
 public:
  std::vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    std::vector<int> result;
    find_target(root, target, K, result);
    return result;
  }

 private:
  int find_target(TreeNode* root, TreeNode* target, int K,
                  std::vector<int>& result) {
    if (!root) return -1;
    if (root == target) {
      find_distance(root, K, result);
      return 1;
    }
    auto left_distance = find_target(root->left, target, K, result);
    if (left_distance != -1) {
      if (left_distance == K) {
        result.push_back(root->val);
      } else if (left_distance < K) {
        find_distance(root->right, K - left_distance - 1, result);
      }
      return left_distance + 1;
    }
    auto right_distance = find_target(root->right, target, K, result);
    if (right_distance != -1) {
      if (right_distance == K) {
        result.push_back(root->val);
      } else if (right_distance < K) {
        find_distance(root->left, K - right_distance - 1, result);
      }
      return right_distance + 1;
    }
    return -1;
  }

  void find_distance(TreeNode* root, int K, std::vector<int>& result) {
    if (!root) return;
    if (K == 0) {
      result.push_back(root->val);
    }
    find_distance(root->left, K - 1, result);
    find_distance(root->right, K - 1, result);
  }
};

TEST_CASE("All Nodes Distance K in Binary Tree") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"3, 5, 1, 6, 2, 0, 8, null, null, 7, 4"};
    REQUIRE_EQ(s.distanceK(tree.root, tree.root->left, 2),
               std::vector<int>{7, 4, 1});
  }

  SUBCASE("Case 2") {
    Tree tree{"0, 1, null, 3, 2"};
    REQUIRE_EQ(s.distanceK(tree.root, tree.root->left->right, 1),
               std::vector<int>{1});
  }

  SUBCASE("Case 3") {
    Tree tree{"0, 2, 1, null, null, 3"};
    REQUIRE_EQ(s.distanceK(tree.root, tree.root->right->left, 3),
               std::vector<int>{2});
  }
}
