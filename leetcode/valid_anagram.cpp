#include <doctest/doctest.h>

#include <string>
#include <vector>

// 242. Valid Anagram
class Solution {
 public:
  bool isAnagram(const std::string& s, const std::string& t) {
    std::vector<int> table(26, 0);
    for (auto ch : s) {
      table[ch - 'a']++;
    }
    for (auto ch : t) {
      table[ch - 'a']--;
    }
    for (auto count : table) {
      if (count != 0) {
        return false;
      }
    }
    return true;
  }
};

TEST_CASE("Valid anagram") {
  Solution s;
  REQUIRE(s.isAnagram("anagram", "nagaram"));
}

TEST_CASE("Valid anagram with different length") {
  Solution s;
  REQUIRE(!s.isAnagram("a", "ab"));
}
