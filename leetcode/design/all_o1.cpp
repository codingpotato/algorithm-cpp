#include <doctest/doctest.h>

#include <map>
#include <set>
#include <string>

// 432. All O`one Data Structure
namespace {

class AllOne {
 public:
  AllOne() {}

  void inc(const std::string key) {
    if (keys.find(key) != keys.end()) {
      frequency[keys[key]].erase(key);
      if (frequency[keys[key]].empty()) {
        frequency.erase(keys[key]);
      }
    }
    ++keys[key];
    frequency[keys[key]].insert(key);
  }

  void dec(const std::string key) {
    if (keys.find(key) != keys.end()) {
      frequency[keys[key]].erase(key);
      if (frequency[keys[key]].empty()) {
        frequency.erase(keys[key]);
      }
      --keys[key];
      if (keys[key] == 0) {
        keys.erase(key);
      } else {
        frequency[keys[key]].insert(key);
      }
    }
  }

  std::string getMaxKey() {
    if (frequency.empty()) {
      return "";
    } else {
      return *(frequency.rbegin()->second.begin());
    }
  }

  std::string getMinKey() {
    if (frequency.empty()) {
      return "";
    } else {
      return *(frequency.cbegin()->second.begin());
    }
  }

 private:
  std::map<std::string, int> keys;
  std::map<int, std::set<std::string>> frequency;
};

}  // namespace

TEST_CASE("All O`one Data Structure") {
  SUBCASE("Case 1") {
    AllOne all_one;
    all_one.inc("a");
    all_one.inc("b");
    all_one.inc("b");
    all_one.inc("b");
    all_one.inc("b");
    all_one.dec("b");
    all_one.dec("b");
    REQUIRE_EQ(all_one.getMaxKey(), "b");
    REQUIRE_EQ(all_one.getMinKey(), "a");
  }

  SUBCASE("Case 2") {
    AllOne all_one;
    all_one.inc("hello");
    all_one.inc("hello");
    REQUIRE_EQ(all_one.getMaxKey(), "hello");
    REQUIRE_EQ(all_one.getMinKey(), "hello");
    all_one.inc("leet");
    REQUIRE_EQ(all_one.getMaxKey(), "hello");
    REQUIRE_EQ(all_one.getMinKey(), "leet");
  }

  SUBCASE("Case 3") {
    AllOne all_one;
    REQUIRE_EQ(all_one.getMaxKey(), "");
    REQUIRE_EQ(all_one.getMinKey(), "");
  }
}
