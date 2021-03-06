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
      if (values[index] != "null") {
        node->left = new TreeNode{std::stoi(values[index])};
        queue.push(node->left);
      }
      ++index;
      if (index < values.size()) {
        if (values[index] != "null") {
          node->right = new TreeNode{std::stoi(values[index])};
          queue.push(node->right);
        }
        ++index;
      }
    }
  }

  std::string serialize() {
    std::string result;
    std::queue<TreeNode *> queue;
    if (root) queue.push(root);
    while (!queue.empty()) {
      auto node = queue.front();
      queue.pop();
      if (node) {
        result += std::to_string(node->val) + ",";
        if (node->left || node->right) {
          queue.push(node->left);
          queue.push(node->right);
        }
      } else {
        result += "null,";
      }
    }
    if (!result.empty()) {
      result.pop_back();
      auto pos = result.rfind("null");
      if (pos != std::string::npos && pos + 4 == result.size()) {
        result.erase(pos - 1);
      }
    }
    return result;
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
  SUBCASE("Case 1") {
    Tree tree{""};
    REQUIRE_EQ(tree.serialize(), "");
  }

  SUBCASE("Case 2") {
    Tree tree{"1, 2, 3"};
    REQUIRE_EQ(tree.serialize(), "1,2,3");
  }

  SUBCASE("Case 3") {
    Tree tree{"1, null, 2, 3"};
    REQUIRE_EQ(tree.serialize(), "1,null,2,3");
  }

  SUBCASE("Case 4") {
    Tree tree{"5, 4, 7, 3, null, 2, null, -1, null, 9"};
    REQUIRE_EQ(tree.serialize(), "5,4,7,3,null,2,null,-1,null,9");
  }
}

#endif  // __TREE__H__
