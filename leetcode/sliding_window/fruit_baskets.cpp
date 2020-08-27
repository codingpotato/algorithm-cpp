#include <doctest/doctest.h>

#include <map>
#include <vector>

// 904. Fruit Into Baskets
class Solution {
 public:
  int totalFruit(const std::vector<int>& tree) {
    std::map<int, int> map;
    int size = tree.size();
    int left = 0;
    int right = 0;
    map[tree[0]] = 0;
    int max = 0;
    while (right < size) {
      if (map.size() <= 2) {
        max = std::max(max, right - left + 1);
        ++right;
        if (right < size) {
          map[tree[right]] = right;
        }
      } else {
        int key = 0;
        int min_index = tree.size();
        for (auto& kv : map) {
          if (kv.second < min_index) {
            key = kv.first;
            min_index = std::min(min_index, kv.second);
          }
        }
        left = min_index + 1;
        map.erase(key);
      }
    }
    return max;
  }
};

TEST_CASE("Fruit Into Baskets") {
  Solution s;
  REQUIRE_EQ(s.totalFruit({1, 2, 1}), 3);
  REQUIRE_EQ(s.totalFruit({0, 1, 2, 2}), 3);
  REQUIRE_EQ(s.totalFruit({1, 2, 3, 2, 2}), 4);
  REQUIRE_EQ(s.totalFruit({3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4}), 5);
}
