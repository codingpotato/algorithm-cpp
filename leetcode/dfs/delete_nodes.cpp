#include <doctest/doctest.h>

#include <set>
#include <vector>

#include "tree.h"

// 1110. Delete Nodes And Return Forest
class Solution {
 public:
  std::vector<TreeNode*> delNodes(TreeNode* root,
                                  const std::vector<int>& to_delete) {
    std::vector<TreeNode*> forest;
    std::set<int> delete_set{to_delete.begin(), to_delete.end()};
    delNodes(root, delete_set, forest, true);
    return forest;
  }

 private:
  bool delNodes(TreeNode* root, const std::set<int>& to_delete,
                std::vector<TreeNode*>& forest, bool in_forest) {
    if (!root) return false;
    auto deleted = to_delete.find(root->val) != to_delete.end();
    if (in_forest && !deleted) {
      forest.push_back(root);
    }
    if (delNodes(root->left, to_delete, forest, deleted)) {
      root->left = nullptr;
    }
    if (delNodes(root->right, to_delete, forest, deleted)) {
      root->right = nullptr;
    }
    return deleted;
  }
};

TEST_CASE("Delete Nodes And Return Forest") {
  Solution s;

  SUBCASE("Case 1") {
    Tree tree{"1, 2, 3, 4, 5, 6, 7"};
    auto trees = s.delNodes(tree.root, {3, 5});
    Tree tree1{"1, 2, null, 4"};
    Tree tree2{"6"};
    Tree tree3{"7"};
    const std::vector<TreeNode*> expected{tree1.root, tree2.root, tree3.root};
    REQUIRE_EQ(trees.size(), expected.size());
    for (size_t i = 0; i < trees.size(); ++i) {
      REQUIRE(is_same(trees[i], expected[i]));
    }
  }

  SUBCASE("Case 2") {
    Tree tree{"1, 2, null, 4, 3"};
    auto trees = s.delNodes(tree.root, {2, 3});
    Tree tree1{"1"};
    Tree tree2{"4"};
    const std::vector<TreeNode*> expected{tree1.root, tree2.root};
    REQUIRE_EQ(trees.size(), expected.size());
    for (size_t i = 0; i < trees.size(); ++i) {
      REQUIRE(is_same(trees[i], expected[i]));
    }
  }
}
