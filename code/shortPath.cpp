// Author: Josh Hartigan
// Description: Given the coordinates of two points in a 10x10 matrix,
//              this program will return the vector of the shortest path
//              to get from the first point to the other, in a situation
//              where the movement must be straight and non-diagonal.

#include <iostream>
#include <array>

std::array<int, 2> getShortestPath(int x1, int y1, int x2, int y2) {
  std::array<int, 2> vec = {{
    x2 - x1 + 1,
    y2 - y1 + 1
  }};
  return vec;
}

int main() {
  int firstPointX; int firstPointY;
  int secondPointX; int secondPointY;

  // get coordinates of first point/node
  std::cout << "\nFirst Point:\n"
            << "\tX-Position? - ";
  std::cin >> firstPointX;
  std::cout << "\tY-Position? - ";
  std::cin >> firstPointY;

  // get coordinates of second point/node
  std::cout << "\nSecond Point:\n"
            << "\tX-Position? - ";
  std::cin >> secondPointX;
  std::cout << "\tY-Position? - ";
  std::cin >> secondPointY;

  std::array<int, 2> path = getShortestPath(firstPointX, firstPointY, secondPointX, secondPointY);
  // print values of path
  std::cout << "\nShortest non-diagonal path: (" << std::get<0>(path) << ", " << std::get<1>(path) << ")\n";
}
