#include <doctest/doctest.h>

#include <string>
#include <vector>

// 720. Longest Word in Dictionary
class Solution {
 public:
  std::string longestWord(const std::vector<std::string>& words) {
    auto root = build_trie(words);
    std::string longest_word = "";
    for (const auto& word : words) {
      auto current = root;
      auto can_be_built = true;
      for (auto i = 0; i < word.size(); ++i) {
        const auto index = word[i] - 'a';
        if (!current->children[index]->end_of_word) {
          can_be_built = false;
          break;
        }
        current = current->children[index];
      }
      if (can_be_built &&
          (word.size() > longest_word.size() ||
           word.size() == longest_word.size() && word < longest_word)) {
        longest_word = word;
      }
    }
    delete root;
    return longest_word;
  }

 private:
  struct TrieNode {
    TrieNode(char ch, bool end_of_word)
        : ch{ch}, end_of_word{end_of_word}, children{26, nullptr} {}

    ~TrieNode() {
      for (const auto child : children) {
        if (child) {
          delete child;
        }
      }
    }

    char ch;
    bool end_of_word;
    std::vector<TrieNode*> children;
  };

  TrieNode* build_trie(const std::vector<std::string>& words) {
    auto root = new TrieNode{0, false};
    for (const auto& word : words) {
      auto current = root;
      for (auto i = 0; i < word.size(); ++i) {
        const auto index = word[i] - 'a';
        if (current->children[index]) {
          if (i == word.size() - 1) {
            current->children[index]->end_of_word = true;
          }
        } else {
          current->children[index] =
              new TrieNode(word[i], i == word.size() - 1);
        }
        current = current->children[index];
      }
    }
    return root;
  }
};

TEST_CASE("Longest Word in Dictionary") {
  Solution s;
  REQUIRE_EQ(s.longestWord({"w", "wo", "wor", "worl", "world"}), "world");
  REQUIRE_EQ(
      s.longestWord({"a", "banana", "app", "appl", "ap", "apply", "apple"}),
      "apple");
}
