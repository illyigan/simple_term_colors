#include <iostream>
#include "stc.hpp"

int main() {
  using namespace std;
  cout << stc::hsl_fg(0.3, 1, 0.5) << "Background and foreground colors can be " << stc::hsl_bg(0.7, 1, 0.5) << "layered over each other." << stc::reset << '\n';

  constexpr auto my_fav_color = stc::rgb_fg(95, 21, 191);
  cout << my_fav_color << "When you provide an HSL or RGB representation of a color, the library will look for a closest match in the 256 color table at compile time.\n" << stc::reset;
  static_assert(my_fav_color.code == 55); // passes

  cout << stc::rgb_fg(255, 0, 0) << "This text is red,\n" << stc::reset;
  cout << stc::no_color << stc::rgb_fg(255, 0, 0) << "But this isn't because we set the color mode to no-color\n" << stc::reset;

  cout << stc::true_color << stc::hsl_fg(0.55, 0.9, 0.8) << "True color support enabled. See colors.cpp example for better visualisation.\n";
  return 0;
}