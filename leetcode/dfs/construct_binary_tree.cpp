#include <doctest/doctest.h>

#include <unordered_map>
#include <vector>

#include "tree.h"

// 105. Construct Binary Tree from Preorder and Inorder Traversal
class Solution {
 public:
  TreeNode* buildTree(const std::vector<int>& preorder,
                      const std::vector<int>& inorder) {
    std::unordered_map<int, int> inorder_map;
    for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
      inorder_map[inorder[i]] = i;
    }
    return buildTree(preorder, 0, preorder.size() - 1, inorder_map, 0,
                     inorder.size() - 1);
  }

 private:
  TreeNode* buildTree(const std::vector<int>& preorder, int left_p, int right_p,
                      const std::unordered_map<int, int>& inorder_map,
                      int left_i, int right_i) {
    if (left_p > right_p) return nullptr;
    auto mid = inorder_map.at(preorder[left_p]);
    auto left_len = mid - left_i;
    auto node = new TreeNode{preorder[left_p]};
    node->left = buildTree(preorder, left_p + 1, left_p + left_len, inorder_map,
                           left_i, mid - 1);
    node->right = buildTree(preorder, left_p + left_len + 1, right_p,
                            inorder_map, mid + 1, right_i);
    return node;
  }
};

TEST_CASE("Construct Binary Tree from Preorder and Inorder Traversal") {
  Solution s;
  auto head = s.buildTree({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7});
  Tree expected{"3, 9, 20, null, null, 15, 7"};
  REQUIRE_EQ(head->val, 3);
  REQUIRE_EQ(head->left->val, 9);
  REQUIRE(is_same(head, expected.root));
}
