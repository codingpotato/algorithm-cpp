#include <doctest/doctest.h>

#include <vector>

// 1004. Max Consecutive Ones III
class Solution {
 public:
  int longestOnes(const std::vector<int>& A, int K) {
    auto lens = get_lens(A);
    size_t left = 1;
    size_t right = 1;
    int len_0 = lens[1];
    int len_1 = lens[0];
    int max_len = 0;
    while (left < lens.size()) {
      if (len_0 > K) {
        len_0 -= lens[left];
        len_1 -= lens[left - 1];
        left += 2;
      } else {
        right += 2;
        if (right >= lens.size()) break;
        len_1 += lens[right - 1];
        len_0 += lens[right];
        max_len = std::max(max_len, len_1 + K);
      }
    }
    return std::min(max_len, static_cast<int>(A.size()));
  }

 private:
  std::vector<int> get_lens(const std::vector<int>& A) {
    std::vector<int> result;
    if (A[0] == 0) result.push_back(0);
    size_t i = 0;
    while (i < A.size()) {
      auto current = A[i];
      auto count = 0;
      while (i < A.size() && A[i] == current) {
        ++count;
        ++i;
      }
      result.push_back(count);
    }
    if (A.back() == 1) result.push_back(0);
    return result;
  }
};

TEST_CASE("Max Consecutive Ones III") {
  Solution s;
  REQUIRE_EQ(s.longestOnes({1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2), 6);
  REQUIRE_EQ(s.longestOnes(
                 {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3),
             10);
  REQUIRE_EQ(s.longestOnes({0, 0, 0, 1}, 4), 4);
}
