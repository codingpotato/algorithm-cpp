#include <doctest/doctest.h>

#include <string>
#include <vector>

// 97. Interleaving String
class Solution {
 public:
  bool isInterleave(const std::string& s1, const std::string& s2,
                    const std::string& s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    std::vector<std::vector<int>> table{s1.size() + 1,
                                        std::vector<int>(s2.size() + 1, -1)};
    return isInterleave(s1, 0, s2, 0, s3, 0, table);
  }

 private:
  bool isInterleave(const std::string& s1, int index1, const std::string& s2,
                    int index2, const std::string& s3, int index,
                    std::vector<std::vector<int>>& table) {
    if (table[index1][index2] == -1) {
      table[index1][index2] =
          (index == static_cast<int>(s3.size()) ||
           (index1 < static_cast<int>(s1.size()) && s3[index] == s1[index1] &&
            isInterleave(s1, index1 + 1, s2, index2, s3, index + 1, table)) ||
           (index2 < static_cast<int>(s2.size()) && s3[index] == s2[index2] &&
            isInterleave(s1, index1, s2, index2 + 1, s3, index + 1, table)))
              ? 1
              : 0;
    }
    return table[index1][index2];
  }
};

TEST_CASE("Interleaving string") {
  Solution s;
  REQUIRE(s.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
  REQUIRE_FALSE(s.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
}
