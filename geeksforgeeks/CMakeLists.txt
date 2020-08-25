set(SOURCES array/subarray_with_sum.cpp)

add_library(geeksforgeeks STATIC ${SOURCES})
target_include_directories(geeksforgeeks PUBLIC ../helper ${DOCTEST_DIR})
target_compile_options(geeksforgeeks PUBLIC -Wall -Werror -Wextra)
