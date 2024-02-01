#include "stc.hpp"
#include <iostream>

void print_rainbow(std::string_view text) {
  const size_t size = text.length();
  for (size_t i = 0; i < size; i++) {
    const auto progress = (float)i / (float)size;
    std::cout << stc::hsl_fg(progress, 1, 0.7) << text[i];
  }
  std::cout << stc::reset;
}

int main() {
  std::cout << "is a " << stc::bold << "C++20 header-only library "
            << stc::reset << "for manipulating ";
  print_rainbow("terminal output colors");
  std::cout << " using " << stc::underline << "ANSI escape sequences"
            << stc::reset << ".\n";
  return 0;
}