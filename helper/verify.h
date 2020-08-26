#ifndef __VERIFY__H__
#define __VERIFY__H__

#include <set>
#include <vector>

template <typename T>
inline bool is_vector_equal_without_order(const std::vector<T>& lhs,
                                          const std::vector<T>& rhs) {
  return std::set<T>(lhs.begin(), lhs.end()) ==
         std::set<T>(rhs.begin(), rhs.end());
}

#endif  // __VERIFY__H__
