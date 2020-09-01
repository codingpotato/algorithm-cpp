#include <doctest/doctest.h>

#include <queue>
#include <vector>

// 1361. Validate Binary Tree Nodes
class Solution {
 public:
  bool validateBinaryTreeNodes(int n, const std::vector<int>& leftChild,
                               const std::vector<int>& rightChild) {
    std::queue<int> queue;
    auto root = find_root(n, leftChild, rightChild);
    if (root == -1) return false;
    queue.push(root);
    std::vector<bool> visited(n);
    while (!queue.empty()) {
      auto index = queue.front();
      queue.pop();
      if (visited[index]) return false;
      visited[index] = true;
      if (leftChild[index] != -1) {
        queue.push(leftChild[index]);
      }
      if (rightChild[index] != -1) {
        queue.push(rightChild[index]);
      }
    }
    for (const auto v : visited) {
      if (!v) return false;
    }
    return true;
  }

 private:
  int find_root(int n, const std::vector<int>& leftChild,
                const std::vector<int>& rightChild) {
    std::vector<bool> has_in(n);
    for (const auto index : leftChild) {
      if (index != -1) has_in[index] = true;
    }
    for (const auto index : rightChild) {
      if (index != -1) has_in[index] = true;
    }
    for (size_t i = 0; i < has_in.size(); ++i) {
      if (!has_in[i]) {
        return i;
      }
    }
    return -1;
  }
};

TEST_CASE("Validate Binary Tree Nodes") {
  Solution s;
  REQUIRE(s.validateBinaryTreeNodes(4, {1, -1, 3, -1}, {2, -1, -1, -1}));
  REQUIRE_FALSE(s.validateBinaryTreeNodes(4, {1, -1, 3, -1}, {2, 3, -1, -1}));
  REQUIRE_FALSE(s.validateBinaryTreeNodes(2, {1, 0}, {-1, -1}));
  REQUIRE_FALSE(s.validateBinaryTreeNodes(6, {1, -1, -1, 4, -1, -1},
                                          {2, -1, -1, 5, -1, -1}));
  REQUIRE(s.validateBinaryTreeNodes(2, {-1, 0}, {-1, -1}));
}
