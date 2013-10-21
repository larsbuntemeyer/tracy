#include <cmath>
#include <string>
#include <vector>
#include <iostream>

#include "quickcg.h"
using namespace QuickCG;

//place the example code below here:

int main(int /*argc*/, char */*argv*/[])
{
  screen(512, 512, 0, "Small Test Script");
  for(int x = 0; x < w; x++)
  for(int y = 0; y < h; y++)
  {
    pset(x, y, ColorRGB(x, y, 128));
  }
  print("Hello, world!", 8, 8);
  
  std::string test;
  test.resize(20);
  
  redraw();
  sleep();
}
