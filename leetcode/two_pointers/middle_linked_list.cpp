#include <doctest/doctest.h>

#include <memory>
#include <utility>
#include <vector>

#include "list.h"

// 876. Middle of the Linked List
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    auto fast = head;
    auto slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return fast->next ? slow->next : slow;
  }
};

TEST_CASE("Middle linked list") {
  Solution s;

  SUBCASE("One middle node") {
    List list{1, 2, 3, 4, 5};
    auto node = s.middleNode(list.head);
    REQUIRE_EQ(node->val, 3);
  }

  SUBCASE("Two middle nodes") {
    List list{1, 2, 3, 4, 5, 6};
    auto node = s.middleNode(list.head);
    REQUIRE_EQ(node->val, 4);
  }
}
