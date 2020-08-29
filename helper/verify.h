#ifndef __VERIFY__H__
#define __VERIFY__H__

#include <set>
#include <vector>

#include "list.h"
#include "tree.h"

template <typename T>
inline bool is_vector_equal_without_order(const std::vector<T>& lhs,
                                          const std::vector<T>& rhs) {
  return std::set<T>(lhs.begin(), lhs.end()) ==
         std::set<T>(rhs.begin(), rhs.end());
}

inline void verify_list(const ListNode* head,
                        const std::vector<int>& expected) {
  for (auto n : expected) {
    REQUIRE_EQ(head->val, n);
    head = head->next;
  }
  REQUIRE_EQ(head, nullptr);
}

#endif  // __VERIFY__H__
