#include <doctest/doctest.h>

#include <string>
#include <vector>

// 208. Implement Trie (Prefix Tree)
class Trie {
 public:
  Trie() : root{new TrieNode} {}

  void insert(const std::string& word) {
    auto current = root;
    for (size_t i = 0; i < word.size(); ++i) {
      auto index = word[i] - 'a';
      if (!current->children[index]) {
        current->children[index] = new TrieNode;
      }
      current = current->children[index];
    }
    current->is_end = true;
  }

  bool search(const std::string& word) {
    auto current = root;
    for (size_t i = 0; i < word.size(); ++i) {
      auto index = word[i] - 'a';
      if (!current->children[index]) return false;
      current = current->children[index];
    }
    return current->is_end;
  }

  bool startsWith(const std::string& prefix) {
    auto current = root;
    for (size_t i = 0; i < prefix.size(); ++i) {
      auto index = prefix[i] - 'a';
      if (!current->children[index]) return false;
      current = current->children[index];
    }
    return true;
  }

 private:
  struct TrieNode {
    TrieNode() : children{'z' - 'a' + 1} {}

    bool is_end = false;
    std::vector<TrieNode*> children;
  };

  TrieNode* root;
};

TEST_CASE("Implement Trie (Prefix Tree)") {
  Trie trie;
  trie.insert("apple");
  REQUIRE(trie.search("apple"));
  REQUIRE_FALSE(trie.search("app"));
  REQUIRE(trie.startsWith("app"));
  trie.insert("app");
  REQUIRE(trie.search("app"));
}
