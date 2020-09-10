#include <doctest/doctest.h>

#include <cstdint>

// 190. Reverse Bits
namespace {

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    uint32_t mask = 1;
    while (mask != 0) {
      result = (result << 1) | ((n & mask) ? 1 : 0);
      mask <<= 1;
    }
    return result;
  }
};

}  // namespace

TEST_CASE("Reverse Bits") {
  Solution s;
  REQUIRE_EQ(s.reverseBits(43261596), 964176192);
  REQUIRE_EQ(s.reverseBits(4294967293), 3221225471);
}
