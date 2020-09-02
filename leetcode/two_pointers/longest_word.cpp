#include <doctest/doctest.h>

#include <string>
#include <vector>

// 524. Longest Word in Dictionary through Deleting
class Solution {
 public:
  std::string findLongestWord(const std::string s,
                              const std::vector<std::string>& d) {
    std::string result;
    for (const auto& word : d) {
      size_t i = 0;
      size_t j = 0;
      while (i < s.size() && j < word.size()) {
        if (s[i] == word[j]) {
          ++i;
          ++j;
        } else {
          ++i;
        }
      }
      if (j == word.size()) {
        if (result.empty() || word.size() > result.size() ||
            (word.size() == result.size() && word < result)) {
          result = word;
        }
      }
    }
    return result;
  }
};

TEST_CASE("Longest Word in Dictionary through Deleting") {
  Solution s;
  REQUIRE_EQ(s.findLongestWord("abpcplea", {"ale", "apple", "monkey", "plea"}),
             "apple");
  REQUIRE_EQ(s.findLongestWord("abpcplea", {"a", "b", "c"}), "a");
}
