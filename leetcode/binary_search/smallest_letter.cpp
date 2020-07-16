#include <doctest/doctest.h>

#include <vector>

// 744. Find Smallest Letter Greater Than Target
class Solution {
 public:
  char nextGreatestLetter(const std::vector<char>& letters, char target) {
    int left = 0;
    int right = letters.size() - 1;
    while (left <= right) {
      auto mid = left + (right - left) / 2;
      if (letters[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left < letters.size() ? letters[left] : letters[0];
  }
};

TEST_CASE("Find smallest letter") {
  Solution s;
  REQUIRE_EQ(s.nextGreatestLetter({'c', 'f', 'j'}, 'a'), 'c');
  REQUIRE_EQ(s.nextGreatestLetter({'c', 'f', 'j'}, 'c'), 'f');
  REQUIRE_EQ(s.nextGreatestLetter({'c', 'f', 'j'}, 'd'), 'f');
  REQUIRE_EQ(s.nextGreatestLetter({'c', 'f', 'j'}, 'g'), 'j');
  REQUIRE_EQ(s.nextGreatestLetter({'c', 'f', 'j'}, 'j'), 'c');
  REQUIRE_EQ(s.nextGreatestLetter({'c', 'f', 'j'}, 'k'), 'c');
}
