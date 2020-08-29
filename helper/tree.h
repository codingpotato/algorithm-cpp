#ifndef __TREE__H__
#define __TREE__H__

#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

struct TreeNode {
  TreeNode(int val) : val{val} {}

  int val;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;
};

inline std::string &ltrim(std::string &str) {
  auto it = std::find_if(str.begin(), str.end(),
                         [](auto ch) { return !std::isspace(ch); });
  str.erase(str.begin(), it);
  return str;
}

inline std::string &rtrim(std::string &str) {
  auto it = std::find_if(str.rbegin(), str.rend(),
                         [](auto ch) { return !std::isspace(ch); });
  str.erase(it.base(), str.end());
  return str;
}

inline std::string &trim(std::string str) { return ltrim(rtrim(str)); }

inline std::vector<std::string> split(const std::string string) {
  std::vector<std::string> result;
  std::istringstream iss{string};
  std::string token;
  while (std::getline(iss, token, ',')) {
    result.push_back(trim(token));
  }
  return result;
}

struct Tree {
  Tree(const std::string &string) {
    auto values = split(string);
    if (values.empty() || values[0] == "null") {
      return;
    }
    std::queue<TreeNode *> queue;
    root = new TreeNode{std::stoi(values[0])};
    queue.push(root);
    size_t index = 1;
    while (index < values.size()) {
      auto node = queue.front();
      queue.pop();
      if (node) {
        if (values[index] != "null") {
          node->left = new TreeNode{std::stoi(values[index])};
        }
        queue.push(node->left);
        ++index;
        if (index < values.size()) {
          if (values[index] != "null") {
            node->right = new TreeNode{std::stoi(values[index])};
          }
          queue.push(node->right);
          ++index;
        }
      } else {
        index += 2;
      }
    }
  }

  TreeNode *root = nullptr;
};

inline bool is_same(const TreeNode *root1, const TreeNode *root2) {
  return (!root1 && !root2) || (root1 && root2 && root1->val == root2->val &&
                                is_same(root1->left, root2->left) &&
                                is_same(root1->right, root2->right));
}

TEST_CASE("split") {
  std::string string{"1, 2, 3"};
  REQUIRE_EQ(split(string), std::vector<std::string>{"1", "2", "3"});
}

TEST_CASE("Tree constructor") {
  Tree tree{"1, 2, 3"};
  REQUIRE_EQ(tree.root->val, 1);
  REQUIRE_EQ(tree.root->left->val, 2);
  REQUIRE_EQ(tree.root->right->val, 3);
}

#endif  // __TREE__H__
