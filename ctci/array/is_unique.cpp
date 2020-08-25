#include <doctest/doctest.h>

#include <set>
#include <string>

std::string isUnique(const std::string& s) {
  std::set<char> set{s.begin(), s.end()};
  return set.size() == s.size() ? "YES" : "NO";
}

TEST_CASE("Is Unique") {
  REQUIRE_EQ(isUnique("abcdef"), "YES");
  REQUIRE_EQ(isUnique("abcdefga"), "NO");
}
