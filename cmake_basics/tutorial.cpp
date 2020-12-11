#include <cmath>
#include <cstdlib>
#include <iostream>
#include "tutorial_config.h"

#ifdef USE_MYMATH
# include "MathFunctions.h"
#endif

using std::stod;
using std::cout;
using std::endl;
using std::sqrt;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    cout << "Usage: " << argv[0] << " number" << endl;
    return 1;
  }

  const double inputValue = stod(argv[1]);

  #ifdef USE_MYMATH
    const double outputValue = mysqrt(inputValue);
  #else
    const double outputValue = sqrt(inputValue);
  #endif

  cout << "The square root of " << inputValue << " is " << outputValue << endl;
  return 0;
}
