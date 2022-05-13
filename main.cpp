
/* Add dependencies */
#include <iostream>

/* Add external files */
#include "./tools/Color.h"

using namespace std;

int main()
{
  cout << Color::getColor(Color::GREEN) << "WELCOME TO CPP TEMPLATE PROJECT" << endl;
  cout << Color::getColorBold(Color::MAGENTA) << "Please, visit the REAMDE file for guide" << endl;
  cout << Color::getColor(Color::RED) + "████████████████████ : TEST_NUMBER " +
         std::to_string(1);
  return 0;
}
