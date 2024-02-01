#include "stc.hpp"
#include <iostream>

int main(int argc, char **argv) {
  using namespace std;
  
  string mode{};
  if (argc == 2)
    mode = argv[1];
  // 256 color mode is set by default

  if (mode == "--no-color")
    cout << stc::no_color;
  else if (mode == "--true-color")
    cout << stc::true_color;
  
  // no extra logic needed when printing.
  cout << stc::rgb_fg(0, 0, 0) << stc::hsl_bg(0.8, 0.3, 0.6) << "Hello!" << stc::reset << '\n';
  return 0;
}