#include <iostream>

using std::cout;

int main() {
  enum class Color { white, red, blue, yellow };
  Color my_color = Color::red;

  if (my_color == Color::red) {
    cout << "The color of my car is red"
         << "\n";
  } else {
    cout << "The color of my car is not red"
         << "\n";
  }

  enum class Direction { kUp, kLeft, kRight, kDown };

  Direction d = Direction::kRight;

  switch (d) {
  case Direction::kUp:
    cout << "Moving in up direction"
         << "\n";
    break;
  case Direction::kDown:
    cout << "Moving in down direction"
         << "\n";
    break;
  case Direction::kRight:
    cout << "Moving in right direction"
         << "\n";
    break;
  case Direction::kLeft:
    cout << "Moving in left direction"
         << "\n";
    break;
  }
}