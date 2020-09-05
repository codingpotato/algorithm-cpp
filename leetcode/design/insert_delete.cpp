#include <doctest/doctest.h>

#include <unordered_map>
#include <vector>

// 380. Insert Delete GetRandom O(1)
namespace {

class RandomizedSet {
 public:
  RandomizedSet() {}

  bool insert(int val) {
    if (indices.find(val) != indices.end()) return false;
    indices[val] = data.size();
    data.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (indices.find(val) == indices.end()) return false;
    auto index = indices[val];
    auto end = data.size() - 1;
    std::swap(data[index], data[end]);
    indices[data[index]] = index;
    indices[data[end]] = end;
    data.pop_back();
    indices.erase(val);
    return true;
  }

  int getRandom() { return data[std::rand() % data.size()]; }

 private:
  std::vector<int> data;
  std::unordered_map<int, int> indices;
};

}  // namespace

TEST_CASE("Insert Delete GetRandom O(1)") {
  RandomizedSet randomSet;
  REQUIRE_EQ(randomSet.insert(1), true);
  REQUIRE_EQ(randomSet.remove(2), false);
  REQUIRE_EQ(randomSet.insert(2), true);
  auto n = randomSet.getRandom();
  REQUIRE((n == 1 || n == 2));
  REQUIRE_EQ(randomSet.remove(1), true);
  REQUIRE_EQ(randomSet.insert(2), false);
  REQUIRE_EQ(randomSet.getRandom(), 2);
}
