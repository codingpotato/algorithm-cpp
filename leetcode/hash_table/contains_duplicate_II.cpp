#include <doctest/doctest.h>

#include <unordered_map>
#include <vector>

// 219. Contains Duplicate II
class Solution {
 public:
  bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
      if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) {
        return true;
      }
      map[nums[i]] = i;
    }
    return false;
  }
};

TEST_CASE("Contains Duplicate II") {
  Solution s;
  REQUIRE(s.containsNearbyDuplicate({1, 2, 3, 1}, 3));
  REQUIRE(s.containsNearbyDuplicate({1, 0, 1, 1}, 1));
  REQUIRE_FALSE(s.containsNearbyDuplicate({1, 2, 3, 1, 2, 3}, 2));
}
