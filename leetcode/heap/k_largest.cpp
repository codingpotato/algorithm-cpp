#include <doctest/doctest.h>

#include <queue>
#include <vector>

// 703. Kth Largest Element in a Stream
class KthLargest {
 public:
  KthLargest(int k, const std::vector<int>& nums) : k{k} {
    for (const auto n : nums) {
      add(n);
    }
  }

  int add(int val) {
    heap.push(val);
    if (heap.size() > static_cast<size_t>(k)) {
      heap.pop();
    }
    return heap.top();
  }

 private:
  int k;
  std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
};

TEST_CASE("Kth Largest Element in a Stream") {
  KthLargest kthLargest{3, {4, 5, 8, 2}};
  REQUIRE_EQ(kthLargest.add(3), 4);
  REQUIRE_EQ(kthLargest.add(5), 5);
  REQUIRE_EQ(kthLargest.add(10), 5);
  REQUIRE_EQ(kthLargest.add(9), 8);
  REQUIRE_EQ(kthLargest.add(4), 8);
}
