#include <doctest/doctest.h>

#include <string>
#include <unordered_map>

// 76. Minimum Window Substring
class Solution {
 public:
  std::string minWindow(const std::string& s, const std::string& t) {
    std::unordered_map<char, int> chars;
    for (const auto ch : t) {
      ++chars[ch];
    }
    std::unordered_map<char, int> current;
    int matches = 0;
    const int size = s.size();
    const int char_size = chars.size();
    int left = 0;
    int right = 0;
    int min_length = s.size() + 1;
    std::string min_window;
    while (right < size) {
      if (chars.find(s[right]) != chars.end()) {
        ++current[s[right]];
        if (current[s[right]] == chars[s[right]]) {
          ++matches;
        }
        if (matches == char_size) {
          while (matches == char_size) {
            if (current.find(s[left]) != current.end()) {
              --current[s[left]];
              if (current[s[left]] < chars[s[left]]) {
                --matches;
              }
            }
            ++left;
          }
          if (right - left + 2 < min_length) {
            min_length = right - left + 2;
            min_window = s.substr(left - 1, min_length);
          }
        }
      }
      ++right;
    }
    return min_window;
  }
};

TEST_CASE("Minimum Window Substring") {
  Solution s;
  REQUIRE_EQ(s.minWindow("ADOBECODEBANC", "ABC"), "BANC");
  REQUIRE_EQ(s.minWindow("a", "aa"), "");
  REQUIRE_EQ(s.minWindow("bdab", "ab"), "ab");
  REQUIRE_EQ(s.minWindow("aaaaaaaaaaaabbbbbcdd", "abcdd"), "abbbbbcdd");
  REQUIRE_EQ(s.minWindow("cabwefgewcwaefgcf", "cae"), "cwae");
}
