#include <doctest/doctest.h>

#include <map>
#include <string>

// 3. Longest Substring Without Repeating Characters
class Solution {
 public:
  int lengthOfLongestSubstring(const std::string& s) {
    if (s.empty()) return 0;
    std::map<char, int> map;
    int left = 0;
    int right = 0;
    int max_len = 0;
    while (right < static_cast<int>(s.size())) {
      if (map.find(s[right]) == map.end() || map[s[right]] == -1) {
        map[s[right]] = right;
        max_len = std::max(max_len, right - left + 1);
        ++right;
      } else {
        while (left <= map[s[right]]) {
          map[s[left++]] = -1;
        }
      }
    }
    return max_len;
  }
};

TEST_CASE("Longest Substring Without Repeating Characters") {
  Solution s;
  REQUIRE_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
  REQUIRE_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
  REQUIRE_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}
