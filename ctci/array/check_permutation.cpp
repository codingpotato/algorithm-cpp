#include <doctest/doctest.h>

#include <algorithm>
#include <string>

std::string checkPermutation(std::string a, std::string b) {
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  return a == b ? "YES" : "NO";
}

TEST_CASE("Check Permutation") {
  REQUIRE_EQ(checkPermutation("abc", "cab"), "YES");
  REQUIRE_EQ(checkPermutation("car", "cer"), "NO");
}
