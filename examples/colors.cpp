#include <iomanip>
#include <iostream>

#include "stc.hpp"

void print_colors() {
  using namespace std;
  const int sizei = 15;
  const int sizej = sizei * 2;
  for (int i = 0; i < sizei; i++) {
    for (int k = 0; k < 2; k++) {
      if (k == 0)
        cout << stc::true_color;
      else
        cout << stc::color_256;
      for (int j = 0; j < sizej; j++) {
        const int x = i - (sizei / 2), y = j - (sizej / 2);
        const float pi = 3.141593;
        const float h = (pi + atan2((float)x, float(y))) / (2 * pi);
        cout << stc::hsl_bg(h, 1, 0.5F) << " ";
      }
      cout << stc::reset << "   ";
    }
    cout << '\n';
  }
}

int main() {
  print_colors();
  std::cout << "truecolor" << std::setw(33) << "256 color" << '\n';
  return 0;
}