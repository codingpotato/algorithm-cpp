#include <doctest/doctest.h>

#include <string>
#include <vector>

// 139. Word Break
class Solution {
 public:
  bool wordBreak(const std::string& s,
                 const std::vector<std::string>& wordDict) {
    std::vector<int> table(s.size(), -1);
    return wordBreak(s, wordDict, 0, table);
  }

 private:
  bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict,
                 int index, std::vector<int>& table) {
    if (index == static_cast<int>(s.size())) return true;
    if (table[index] == -1) {
      table[index] = 0;
      for (const auto& word : wordDict) {
        if (s.size() - index >= word.size() &&
            std::equal(s.begin() + index, s.begin() + index + word.size(),
                       word.begin()) &&
            wordBreak(s, wordDict, index + word.size(), table)) {
          table[index] = 1;
          break;
        }
      }
    }
    return table[index];
  }
};

TEST_CASE("Word Break") {
  Solution s;
  REQUIRE(s.wordBreak("leetcode", {"leet", "code"}));
  REQUIRE(s.wordBreak("applepenapple", {"apple", "pen"}));
  REQUIRE_FALSE(
      s.wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}));
}
