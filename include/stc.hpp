/*
MIT License

Copyright (c) 2024 illyigan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
#include <array>
#include <ostream>

namespace stc {

enum _color_modes { COLOR_256 = 0, TRUE_COLOR = 1, NO_COLOR = 2 };

inline int _get_color_mode_index() {
  static const int i = std::ios_base::xalloc();
  return i;
}

class _color_data {
public:
  unsigned int r : 8, g : 8, b : 8, code : 8;
  constexpr _color_data(int r, int g, int b, int code)
      : r(r), g(g), b(b), code(code){};
  constexpr ~_color_data() = default;
};

template <bool IS_FOREGROUND> class _color_code : public _color_data {
  using _color_data::_color_data;
};

// foreground
inline std::ostream &operator<<(std::ostream &os,
                                const _color_code<true> &color_code) {
  const long mode = os.iword(_get_color_mode_index());
  if (mode == _color_modes::COLOR_256)
    os << "\033[38;5;" << color_code.code << 'm';
  else if (mode == _color_modes::TRUE_COLOR)
    os << "\033[38;2;" << color_code.r << ';' << color_code.g << ';'
       << color_code.b << 'm';
  return os;
}

// background
inline std::ostream &operator<<(std::ostream &os,
                                const _color_code<false> &color_code) {
  const long mode = os.iword(_get_color_mode_index());
  if (mode == _color_modes::COLOR_256)
    os << "\033[48;5;" << color_code.code << 'm';
  else if (mode == _color_modes::TRUE_COLOR)
    os << "\033[48;2;" << color_code.r << ';' << color_code.g << ';'
       << color_code.b << 'm';
  return os;
}

constexpr const auto _256colors =
    std::to_array({_color_data{0, 0, 0, 0 /*Black(SYSTEM)*/},
                   _color_data{128, 0, 0, 1 /*Maroon(SYSTEM)*/},
                   _color_data{0, 128, 0, 2 /*Green(SYSTEM)*/},
                   _color_data{128, 128, 0, 3 /*Olive(SYSTEM)*/},
                   _color_data{0, 0, 128, 4 /*Navy(SYSTEM)*/},
                   _color_data{128, 0, 128, 5 /*Purple(SYSTEM)*/},
                   _color_data{0, 128, 128, 6 /*Teal(SYSTEM)*/},
                   _color_data{192, 192, 192, 7 /*Silver(SYSTEM)*/},
                   _color_data{128, 128, 128, 8 /*Grey(SYSTEM)*/},
                   _color_data{255, 0, 0, 9 /*Red(SYSTEM)*/},
                   _color_data{0, 255, 0, 10 /*Lime(SYSTEM)*/},
                   _color_data{255, 255, 0, 11 /*Yellow(SYSTEM)*/},
                   _color_data{0, 0, 255, 12 /*Blue(SYSTEM)*/},
                   _color_data{255, 0, 255, 13 /*Fuchsia(SYSTEM)*/},
                   _color_data{0, 255, 255, 14 /*Aqua(SYSTEM)*/},
                   _color_data{255, 255, 255, 15 /*White(SYSTEM)*/},
                   _color_data{0, 0, 0, 16 /*Grey0*/},
                   _color_data{0, 0, 95, 17 /*NavyBlue*/},
                   _color_data{0, 0, 135, 18 /*DarkBlue*/},
                   _color_data{0, 0, 175, 19 /*Blue3*/},
                   _color_data{0, 0, 215, 20 /*Blue3*/},
                   _color_data{0, 0, 255, 21 /*Blue1*/},
                   _color_data{0, 95, 0, 22 /*DarkGreen*/},
                   _color_data{0, 95, 95, 23 /*DeepSkyBlue4*/},
                   _color_data{0, 95, 135, 24 /*DeepSkyBlue4*/},
                   _color_data{0, 95, 175, 25 /*DeepSkyBlue4*/},
                   _color_data{0, 95, 215, 26 /*DodgerBlue3*/},
                   _color_data{0, 95, 255, 27 /*DodgerBlue2*/},
                   _color_data{0, 135, 0, 28 /*Green4*/},
                   _color_data{0, 135, 95, 29 /*SpringGreen4*/},
                   _color_data{0, 135, 135, 30 /*Turquoise4*/},
                   _color_data{0, 135, 175, 31 /*DeepSkyBlue3*/},
                   _color_data{0, 135, 215, 32 /*DeepSkyBlue3*/},
                   _color_data{0, 135, 255, 33 /*DodgerBlue1*/},
                   _color_data{0, 175, 0, 34 /*Green3*/},
                   _color_data{0, 175, 95, 35 /*SpringGreen3*/},
                   _color_data{0, 175, 135, 36 /*DarkCyan*/},
                   _color_data{0, 175, 175, 37 /*LightSeaGreen*/},
                   _color_data{0, 175, 215, 38 /*DeepSkyBlue2*/},
                   _color_data{0, 175, 255, 39 /*DeepSkyBlue1*/},
                   _color_data{0, 215, 0, 40 /*Green3*/},
                   _color_data{0, 215, 95, 41 /*SpringGreen3*/},
                   _color_data{0, 215, 135, 42 /*SpringGreen2*/},
                   _color_data{0, 215, 175, 43 /*Cyan3*/},
                   _color_data{0, 215, 215, 44 /*DarkTurquoise*/},
                   _color_data{0, 215, 255, 45 /*Turquoise2*/},
                   _color_data{0, 255, 0, 46 /*Green1*/},
                   _color_data{0, 255, 95, 47 /*SpringGreen2*/},
                   _color_data{0, 255, 135, 48 /*SpringGreen1*/},
                   _color_data{0, 255, 175, 49 /*MediumSpringGreen*/},
                   _color_data{0, 255, 215, 50 /*Cyan2*/},
                   _color_data{0, 255, 255, 51 /*Cyan1*/},
                   _color_data{95, 0, 0, 52 /*DarkRed*/},
                   _color_data{95, 0, 95, 53 /*DeepPink4*/},
                   _color_data{95, 0, 135, 54 /*Purple4*/},
                   _color_data{95, 0, 175, 55 /*Purple4*/},
                   _color_data{95, 0, 215, 56 /*Purple3*/},
                   _color_data{95, 0, 255, 57 /*BlueViolet*/},
                   _color_data{95, 95, 0, 58 /*Orange4*/},
                   _color_data{95, 95, 95, 59 /*Grey37*/},
                   _color_data{95, 95, 135, 60 /*MediumPurple4*/},
                   _color_data{95, 95, 175, 61 /*SlateBlue3*/},
                   _color_data{95, 95, 215, 62 /*SlateBlue3*/},
                   _color_data{95, 95, 255, 63 /*RoyalBlue1*/},
                   _color_data{95, 135, 0, 64 /*Chartreuse4*/},
                   _color_data{95, 135, 95, 65 /*DarkSeaGreen4*/},
                   _color_data{95, 135, 135, 66 /*PaleTurquoise4*/},
                   _color_data{95, 135, 175, 67 /*SteelBlue*/},
                   _color_data{95, 135, 215, 68 /*SteelBlue3*/},
                   _color_data{95, 135, 255, 69 /*CornflowerBlue*/},
                   _color_data{95, 175, 0, 70 /*Chartreuse3*/},
                   _color_data{95, 175, 95, 71 /*DarkSeaGreen4*/},
                   _color_data{95, 175, 135, 72 /*CadetBlue*/},
                   _color_data{95, 175, 175, 73 /*CadetBlue*/},
                   _color_data{95, 175, 215, 74 /*SkyBlue3*/},
                   _color_data{95, 175, 255, 75 /*SteelBlue1*/},
                   _color_data{95, 215, 0, 76 /*Chartreuse3*/},
                   _color_data{95, 215, 95, 77 /*PaleGreen3*/},
                   _color_data{95, 215, 135, 78 /*SeaGreen3*/},
                   _color_data{95, 215, 175, 79 /*Aquamarine3*/},
                   _color_data{95, 215, 215, 80 /*MediumTurquoise*/},
                   _color_data{95, 215, 255, 81 /*SteelBlue1*/},
                   _color_data{95, 255, 0, 82 /*Chartreuse2*/},
                   _color_data{95, 255, 95, 83 /*SeaGreen2*/},
                   _color_data{95, 255, 135, 84 /*SeaGreen1*/},
                   _color_data{95, 255, 175, 85 /*SeaGreen1*/},
                   _color_data{95, 255, 215, 86 /*Aquamarine1*/},
                   _color_data{95, 255, 255, 87 /*DarkSlateGray2*/},
                   _color_data{135, 0, 0, 88 /*DarkRed*/},
                   _color_data{135, 0, 95, 89 /*DeepPink4*/},
                   _color_data{135, 0, 135, 90 /*DarkMagenta*/},
                   _color_data{135, 0, 175, 91 /*DarkMagenta*/},
                   _color_data{135, 0, 215, 92 /*DarkViolet*/},
                   _color_data{135, 0, 255, 93 /*Purple*/},
                   _color_data{135, 95, 0, 94 /*Orange4*/},
                   _color_data{135, 95, 95, 95 /*LightPink4*/},
                   _color_data{135, 95, 135, 96 /*Plum4*/},
                   _color_data{135, 95, 175, 97 /*MediumPurple3*/},
                   _color_data{135, 95, 215, 98 /*MediumPurple3*/},
                   _color_data{135, 95, 255, 99 /*SlateBlue1*/},
                   _color_data{135, 135, 0, 100 /*Yellow4*/},
                   _color_data{135, 135, 95, 101 /*Wheat4*/},
                   _color_data{135, 135, 135, 102 /*Grey53*/},
                   _color_data{135, 135, 175, 103 /*LightSlateGrey*/},
                   _color_data{135, 135, 215, 104 /*MediumPurple*/},
                   _color_data{135, 135, 255, 105 /*LightSlateBlue*/},
                   _color_data{135, 175, 0, 106 /*Yellow4*/},
                   _color_data{135, 175, 95, 107 /*DarkOliveGreen3*/},
                   _color_data{135, 175, 135, 108 /*DarkSeaGreen*/},
                   _color_data{135, 175, 175, 109 /*LightSkyBlue3*/},
                   _color_data{135, 175, 215, 110 /*LightSkyBlue3*/},
                   _color_data{135, 175, 255, 111 /*SkyBlue2*/},
                   _color_data{135, 215, 0, 112 /*Chartreuse2*/},
                   _color_data{135, 215, 95, 113 /*DarkOliveGreen3*/},
                   _color_data{135, 215, 135, 114 /*PaleGreen3*/},
                   _color_data{135, 215, 175, 115 /*DarkSeaGreen3*/},
                   _color_data{135, 215, 215, 116 /*DarkSlateGray3*/},
                   _color_data{135, 215, 255, 117 /*SkyBlue1*/},
                   _color_data{135, 255, 0, 118 /*Chartreuse1*/},
                   _color_data{135, 255, 95, 119 /*LightGreen*/},
                   _color_data{135, 255, 135, 120 /*LightGreen*/},
                   _color_data{135, 255, 175, 121 /*PaleGreen1*/},
                   _color_data{135, 255, 215, 122 /*Aquamarine1*/},
                   _color_data{135, 255, 255, 123 /*DarkSlateGray1*/},
                   _color_data{175, 0, 0, 124 /*Red3*/},
                   _color_data{175, 0, 95, 125 /*DeepPink4*/},
                   _color_data{175, 0, 135, 126 /*MediumVioletRed*/},
                   _color_data{175, 0, 175, 127 /*Magenta3*/},
                   _color_data{175, 0, 215, 128 /*DarkViolet*/},
                   _color_data{175, 0, 255, 129 /*Purple*/},
                   _color_data{175, 95, 0, 130 /*DarkOrange3*/},
                   _color_data{175, 95, 95, 131 /*IndianRed*/},
                   _color_data{175, 95, 135, 132 /*HotPink3*/},
                   _color_data{175, 95, 175, 133 /*MediumOrchid3*/},
                   _color_data{175, 95, 215, 134 /*MediumOrchid*/},
                   _color_data{175, 95, 255, 135 /*MediumPurple2*/},
                   _color_data{175, 135, 0, 136 /*DarkGoldenrod*/},
                   _color_data{175, 135, 95, 137 /*LightSalmon3*/},
                   _color_data{175, 135, 135, 138 /*RosyBrown*/},
                   _color_data{175, 135, 175, 139 /*Grey63*/},
                   _color_data{175, 135, 215, 140 /*MediumPurple2*/},
                   _color_data{175, 135, 255, 141 /*MediumPurple1*/},
                   _color_data{175, 175, 0, 142 /*Gold3*/},
                   _color_data{175, 175, 95, 143 /*DarkKhaki*/},
                   _color_data{175, 175, 135, 144 /*NavajoWhite3*/},
                   _color_data{175, 175, 175, 145 /*Grey69*/},
                   _color_data{175, 175, 215, 146 /*LightSteelBlue3*/},
                   _color_data{175, 175, 255, 147 /*LightSteelBlue*/},
                   _color_data{175, 215, 0, 148 /*Yellow3*/},
                   _color_data{175, 215, 95, 149 /*DarkOliveGreen3*/},
                   _color_data{175, 215, 135, 150 /*DarkSeaGreen3*/},
                   _color_data{175, 215, 175, 151 /*DarkSeaGreen2*/},
                   _color_data{175, 215, 215, 152 /*LightCyan3*/},
                   _color_data{175, 215, 255, 153 /*LightSkyBlue1*/},
                   _color_data{175, 255, 0, 154 /*GreenYellow*/},
                   _color_data{175, 255, 95, 155 /*DarkOliveGreen2*/},
                   _color_data{175, 255, 135, 156 /*PaleGreen1*/},
                   _color_data{175, 255, 175, 157 /*DarkSeaGreen2*/},
                   _color_data{175, 255, 215, 158 /*DarkSeaGreen1*/},
                   _color_data{175, 255, 255, 159 /*PaleTurquoise1*/},
                   _color_data{215, 0, 0, 160 /*Red3*/},
                   _color_data{215, 0, 95, 161 /*DeepPink3*/},
                   _color_data{215, 0, 135, 162 /*DeepPink3*/},
                   _color_data{215, 0, 175, 163 /*Magenta3*/},
                   _color_data{215, 0, 215, 164 /*Magenta3*/},
                   _color_data{215, 0, 255, 165 /*Magenta2*/},
                   _color_data{215, 95, 0, 166 /*DarkOrange3*/},
                   _color_data{215, 95, 95, 167 /*IndianRed*/},
                   _color_data{215, 95, 135, 168 /*HotPink3*/},
                   _color_data{215, 95, 175, 169 /*HotPink2*/},
                   _color_data{215, 95, 215, 170 /*Orchid*/},
                   _color_data{215, 95, 255, 171 /*MediumOrchid1*/},
                   _color_data{215, 135, 0, 172 /*Orange3*/},
                   _color_data{215, 135, 95, 173 /*LightSalmon3*/},
                   _color_data{215, 135, 135, 174 /*LightPink3*/},
                   _color_data{215, 135, 175, 175 /*Pink3*/},
                   _color_data{215, 135, 215, 176 /*Plum3*/},
                   _color_data{215, 135, 255, 177 /*Violet*/},
                   _color_data{215, 175, 0, 178 /*Gold3*/},
                   _color_data{215, 175, 95, 179 /*LightGoldenrod3*/},
                   _color_data{215, 175, 135, 180 /*Tan*/},
                   _color_data{215, 175, 175, 181 /*MistyRose3*/},
                   _color_data{215, 175, 215, 182 /*Thistle3*/},
                   _color_data{215, 175, 255, 183 /*Plum2*/},
                   _color_data{215, 215, 0, 184 /*Yellow3*/},
                   _color_data{215, 215, 95, 185 /*Khaki3*/},
                   _color_data{215, 215, 135, 186 /*LightGoldenrod2*/},
                   _color_data{215, 215, 175, 187 /*LightYellow3*/},
                   _color_data{215, 215, 215, 188 /*Grey84*/},
                   _color_data{215, 215, 255, 189 /*LightSteelBlue1*/},
                   _color_data{215, 255, 0, 190 /*Yellow2*/},
                   _color_data{215, 255, 95, 191 /*DarkOliveGreen1*/},
                   _color_data{215, 255, 135, 192 /*DarkOliveGreen1*/},
                   _color_data{215, 255, 175, 193 /*DarkSeaGreen1*/},
                   _color_data{215, 255, 215, 194 /*Honeydew2*/},
                   _color_data{215, 255, 255, 195 /*LightCyan1*/},
                   _color_data{255, 0, 0, 196 /*Red1*/},
                   _color_data{255, 0, 95, 197 /*DeepPink2*/},
                   _color_data{255, 0, 135, 198 /*DeepPink1*/},
                   _color_data{255, 0, 175, 199 /*DeepPink1*/},
                   _color_data{255, 0, 215, 200 /*Magenta2*/},
                   _color_data{255, 0, 255, 201 /*Magenta1*/},
                   _color_data{255, 95, 0, 202 /*OrangeRed1*/},
                   _color_data{255, 95, 95, 203 /*IndianRed1*/},
                   _color_data{255, 95, 135, 204 /*IndianRed1*/},
                   _color_data{255, 95, 175, 205 /*HotPink*/},
                   _color_data{255, 95, 215, 206 /*HotPink*/},
                   _color_data{255, 95, 255, 207 /*MediumOrchid1*/},
                   _color_data{255, 135, 0, 208 /*DarkOrange*/},
                   _color_data{255, 135, 95, 209 /*Salmon1*/},
                   _color_data{255, 135, 135, 210 /*LightCoral*/},
                   _color_data{255, 135, 175, 211 /*PaleVioletRed1*/},
                   _color_data{255, 135, 215, 212 /*Orchid2*/},
                   _color_data{255, 135, 255, 213 /*Orchid1*/},
                   _color_data{255, 175, 0, 214 /*Orange1*/},
                   _color_data{255, 175, 95, 215 /*SandyBrown*/},
                   _color_data{255, 175, 135, 216 /*LightSalmon1*/},
                   _color_data{255, 175, 175, 217 /*LightPink1*/},
                   _color_data{255, 175, 215, 218 /*Pink1*/},
                   _color_data{255, 175, 255, 219 /*Plum1*/},
                   _color_data{255, 215, 0, 220 /*Gold1*/},
                   _color_data{255, 215, 95, 221 /*LightGoldenrod2*/},
                   _color_data{255, 215, 135, 222 /*LightGoldenrod2*/},
                   _color_data{255, 215, 175, 223 /*NavajoWhite1*/},
                   _color_data{255, 215, 215, 224 /*MistyRose1*/},
                   _color_data{255, 215, 255, 225 /*Thistle1*/},
                   _color_data{255, 255, 0, 226 /*Yellow1*/},
                   _color_data{255, 255, 95, 227 /*LightGoldenrod1*/},
                   _color_data{255, 255, 135, 228 /*Khaki1*/},
                   _color_data{255, 255, 175, 229 /*Wheat1*/},
                   _color_data{255, 255, 215, 230 /*Cornsilk1*/},
                   _color_data{255, 255, 255, 231 /*Grey100*/},
                   _color_data{8, 8, 8, 232 /*Grey3*/},
                   _color_data{18, 18, 18, 233 /*Grey7*/},
                   _color_data{28, 28, 28, 234 /*Grey11*/},
                   _color_data{38, 38, 38, 235 /*Grey15*/},
                   _color_data{48, 48, 48, 236 /*Grey19*/},
                   _color_data{58, 58, 58, 237 /*Grey23*/},
                   _color_data{68, 68, 68, 238 /*Grey27*/},
                   _color_data{78, 78, 78, 239 /*Grey30*/},
                   _color_data{88, 88, 88, 240 /*Grey35*/},
                   _color_data{98, 98, 98, 241 /*Grey39*/},
                   _color_data{108, 108, 108, 242 /*Grey42*/},
                   _color_data{118, 118, 118, 243 /*Grey46*/},
                   _color_data{128, 128, 128, 244 /*Grey50*/},
                   _color_data{138, 138, 138, 245 /*Grey54*/},
                   _color_data{148, 148, 148, 246 /*Grey58*/},
                   _color_data{158, 158, 158, 247 /*Grey62*/},
                   _color_data{168, 168, 168, 248 /*Grey66*/},
                   _color_data{178, 178, 178, 249 /*Grey70*/},
                   _color_data{188, 188, 188, 250 /*Grey74*/},
                   _color_data{198, 198, 198, 251 /*Grey78*/},
                   _color_data{208, 208, 208, 252 /*Grey82*/},
                   _color_data{218, 218, 218, 253 /*Grey85*/},
                   _color_data{228, 228, 228, 254 /*Grey89*/},
                   _color_data{238, 238, 238, 255 /*Grey93*/}});

constexpr float _color_distance(int r, int g, int b, _color_data color) {
  // approximate color distance using redmean
  // (https://en.wikipedia.org/wiki/Color_difference)
  const auto red_difference = (float)(color.r - r);
  const auto green_difference = (float)(color.g - g);
  const auto blue_difference = (float)(color.b - b);
  const float red_average = (float)(r + color.r) / 2.0F;
  return ((2 + (red_average / 256)) * (red_difference * red_difference)) +
         (4 * (green_difference * green_difference)) +
         ((2 + ((255 - red_average) / 256)) *
          (blue_difference * blue_difference));
}

constexpr int _find_closest_color_code(int r, int g, int b) {
  // for dark colors we return black, the cutoff values are arbitrary but
  // prevent artifacting from redmean color distance approximation
  if (r < 20 && g < 15 && b < 15)
    return _256colors[16].code;
  // we start at index 16, because colors 0 - 16 are system colors (terminal
  // emulators often define custom values for these)
  size_t best_index = 16;
  for (size_t i = best_index; i < _256colors.size(); i++) {
    if (_color_distance(r, g, b, _256colors[i]) <
        _color_distance(r, g, b, _256colors[best_index]))
      best_index = i;
  }
  return _256colors[best_index].code;
}

constexpr void _hsl_to_rgb(float h, float s, float l, int &r, int &g, int &b) {
  auto fmod = [](float number, int divisor) {
    const int i = (int)number;
    return (float)(i % divisor) + (number - (float)i);
  };
  auto round = [](float number) {
    const int i = (int)number;
    if (number - (float)i >= 0.5)
      return i + 1;
    return i;
  };

  // (https://en.wikipedia.org/wiki/HSL_and_HSV#Color_conversion_formulae)
  if (s == 0) {
    r = g = b = round(l * 255);
    return;
  }
  const float alpha = s * std::min(l, 1 - l);
  auto f = [=](float n) {
    const float k = fmod((n + (h * 12)), 12);
    return l - (alpha * std::max(-1.0F, std::min({k - 3, 9 - k, 1.0F})));
  };
  r = round(f(0) * 255);
  g = round(f(8) * 255);
  b = round(f(4) * 255);
}

constexpr void _clamp(int &a, int min, int max) {
  if (a < min)
    a = min;
  else if (a > max)
    a = max;
}

constexpr void _clamp_rgb(int &r, int &g, int &b) {
  _clamp(r, 0, 255);
  _clamp(g, 0, 255);
  _clamp(b, 0, 255);
}

inline std::ostream &_print_if_color(std::ostream &os, std::string_view text) {
  const auto mode = os.iword(_get_color_mode_index());
  if (mode != _color_modes::NO_COLOR)
    return os << text;
  return os;
}

inline std::ostream &color_256(std::ostream &os) {
  os.iword(_get_color_mode_index()) = _color_modes::COLOR_256;
  return os;
}
inline std::ostream &true_color(std::ostream &os) {
  os.iword(_get_color_mode_index()) = _color_modes::TRUE_COLOR;
  return os;
}
inline std::ostream &no_color(std::ostream &os) {
  os.iword(_get_color_mode_index()) = _color_modes::NO_COLOR;
  return os;
}

inline std::ostream &reset(std::ostream &os) {
  return _print_if_color(os, "\033[0m");
}
inline std::ostream &bold(std::ostream &os) {
  return _print_if_color(os, "\033[1m");
}
inline std::ostream &faint(std::ostream &os) {
  return _print_if_color(os, "\033[2m");
}
inline std::ostream &italic(std::ostream &os) {
  return _print_if_color(os, "\033[3m");
}
inline std::ostream &underline(std::ostream &os) {
  return _print_if_color(os, "\033[4m");
}
inline std::ostream &inverse(std::ostream &os) {
  return _print_if_color(os, "\033[7m");
}
inline std::ostream &crossed_out(std::ostream &os) {
  return _print_if_color(os, "\033[9m");
}
inline std::ostream &reset_fg(std::ostream &os) {
  return _print_if_color(os, "\033[39m");
}
inline std::ostream &reset_bg(std::ostream &os) {
  return _print_if_color(os, "\033[49m");
}

constexpr _color_code<true> rgb_fg(int r, int g, int b) {
  _clamp_rgb(r, g, b);
  return {r, g, b, _find_closest_color_code(r, g, b)};
}

constexpr _color_code<false> rgb_bg(int r, int g, int b) {
  _clamp_rgb(r, g, b);
  return {r, g, b, _find_closest_color_code(r, g, b)};
}

constexpr _color_code<true> hsl_fg(float h, float s, float l) {
  int r = 0, g = 0, b = 0;
  _hsl_to_rgb(h, s, l, r, g, b);
  _clamp_rgb(r, g, b);
  return {r, g, b, _find_closest_color_code(r, g, b)};
}

constexpr _color_code<false> hsl_bg(float h, float s, float l) {
  int r = 0, g = 0, b = 0;
  _hsl_to_rgb(h, s, l, r, g, b);
  _clamp_rgb(r, g, b);
  return {r, g, b, _find_closest_color_code(r, g, b)};
}

constexpr _color_code<true> code_fg(int code) {
  _clamp(code, 0, 255);
  const auto color_data = _256colors[code];
  return {color_data.r, color_data.g, color_data.b, color_data.code};
}

constexpr _color_code<false> code_bg(int code) {
  _clamp(code, 0, 255);
  const auto color_data = _256colors[code];
  return {color_data.r, color_data.g, color_data.b, color_data.code};
}

} // namespace stc