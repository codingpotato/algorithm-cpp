#include <doctest/doctest.h>

#include <iostream>
#include <vector>

#include "list.h"

// 61. Rotate List
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return nullptr;

    ListNode dummy{0, head};
    auto fast = &dummy;
    auto n = 0;
    while (k > 0) {
      fast = fast->next;
      --k;
      ++n;
      if (!fast->next) {
        k %= n;
        fast = &dummy;
      }
    }
    auto slow = &dummy;
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }

    if (slow->next) {
      fast->next = head;
      head = slow->next;
      slow->next = nullptr;
    }
    return head;
  }
};

TEST_CASE("Rotate List") {
  Solution s;

  SUBCASE("Case 1") {
    List list{1, 2, 3, 4, 5};
    auto result = s.rotateRight(list.head, 2);
    verify_list(result, std::vector<int>{4, 5, 1, 2, 3});
  }

  SUBCASE("Case 2") {
    List list{0, 1, 2};
    auto result = s.rotateRight(list.head, 4);
    verify_list(result, std::vector<int>{2, 0, 1});
  }
}
