#include "stc.hpp"
#include <iostream>

int main() {
  std::cout << stc::rgb_fg(95, 21, 191) << "This text is now purple. "
            << stc::reset << "And this text is back to normal.\n";
  return 0;
}