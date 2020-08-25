#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>

#include <iostream>

int app_main() {
  std::cout << "Application starting...\n";
  return 0;
}

int main(int argc, char **argv) {
  doctest::Context context;
  context.applyCommandLine(argc, argv);

  int res = context.run();
  if (context.shouldExit()) {
    return res;
  }

  return res;
}
