#include <doctest/doctest.h>

#include <vector>

// 4. Median of Two Sorted Arrays
class Solution {
 public:
  struct ArrayInfo {
    const std::vector<int>* nums;
    int left;
    int right;
  };

  double findMedianSortedArrays(const std::vector<int>& nums1,
                                const std::vector<int>& nums2) {
    int size = nums1.size() + nums2.size();
    auto medain_index = size % 2 ? size / 2 : size / 2 - 1;
    ArrayInfo ai1{&nums1, 0, static_cast<int>(nums1.size()) - 1};
    ArrayInfo ai2{&nums2, 0, static_cast<int>(nums2.size()) - 1};
    while (ai1.left <= ai1.right && ai2.left <= ai2.right) {
      if ((*ai1.nums)[ai1.left] > (*ai2.nums)[ai2.left]) {
        std::swap(ai1, ai2);
      }
      auto mid = ai1.left + (ai1.right - ai1.left) / 2;
      auto first_greater =
          find_greater(*ai2.nums, ai2.left, ai2.right, (*ai1.nums)[mid]);
      auto small_size = mid - ai1.left + 1 + first_greater - ai2.left;
      if (medain_index + 1 == small_size) {
        auto next = 0;
        if (mid < static_cast<int>(ai1.nums->size()) - 1 &&
            first_greater < static_cast<int>(ai2.nums->size())) {
          next = std::min((*ai1.nums)[mid + 1], (*ai2.nums)[first_greater]);
        } else if (mid < static_cast<int>(ai1.nums->size()) - 1) {
          next = (*ai1.nums)[mid + 1];
        } else {
          next = (*ai2.nums)[first_greater];
        }
        return size % 2 ? (*ai1.nums)[mid]
                        : static_cast<double>((*ai1.nums)[mid] + next) / 2;
      } else if (medain_index + 1 < small_size) {
        ai1.right = mid;
        ai2.right = first_greater - 1;
      } else {
        ai1.left = mid + 1;
        ai2.left = first_greater;
        medain_index -= small_size;
      }
    }
    if (ai1.left > ai1.right) {
      return size % 2 ? (*ai2.nums)[ai2.left + medain_index]
                      : static_cast<double>(
                            (*ai2.nums)[ai2.left + medain_index] +
                            (*ai2.nums)[ai2.left + medain_index + 1]) /
                            2;
    } else {
      return size % 2 ? (*ai1.nums)[ai1.left + medain_index]
                      : static_cast<double>(
                            (*ai1.nums)[ai1.left + medain_index] +
                            (*ai1.nums)[ai1.left + medain_index + 1]) /
                            2;
    }
  }

 private:
  int find_greater(const std::vector<int>& nums, int left, int right,
                   int target) {
    while (left < right) {
      auto mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return nums[left] < target ? left + 1 : left;
  }
};

TEST_CASE("Median of Two Sorted Arrays") {
  Solution solution;
  REQUIRE_EQ(solution.findMedianSortedArrays({}, {1}), 1);
  REQUIRE_EQ(solution.findMedianSortedArrays({2}, {}), 2);
  REQUIRE_EQ(solution.findMedianSortedArrays({1, 3}, {2}), 2);
  REQUIRE_EQ(solution.findMedianSortedArrays({1, 2}, {3, 4}), 2.5);
  REQUIRE_EQ(solution.findMedianSortedArrays({0, 0}, {0, 0}), 0);
  REQUIRE_EQ(solution.findMedianSortedArrays({3}, {-2, -1}), -1);
  REQUIRE_EQ(solution.findMedianSortedArrays({1, 2}, {-1, 3}), 1.5);
  REQUIRE_EQ(solution.findMedianSortedArrays({2}, {1, 3, 4, 5}), 3);
  REQUIRE_EQ(solution.findMedianSortedArrays({6}, {1, 2, 3, 4, 5, 7}), 4);
}
