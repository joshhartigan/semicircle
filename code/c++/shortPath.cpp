// Author: Josh Hartigan
// Description: Given the coordinates of two points in a matrix,
//              this program will return the vector of the shortest path
//              to get from the first point to the other, in a situation
//              where the movement must be straight and non-diagonal.

#define _USE_MATH_DEFINES // for the pi constant

#include <iostream>
#include <array>
#include <cmath>
#include <string>

std::array<int, 2> getShortestPath(int x1, int y1, int x2, int y2) {
  std::array<int, 2> vec = {{ x2 - x1, y2 - y1 }};
  return vec;
}

std::array<double, 2> diagonalPath(int x1, int y1, int x2, int y2) {
  double angle;     // angle in degrees of the diagonal path
  double distance;  // the actual length of the path

  // calculate distance
  distance = hypot((x2 - x1), (y2 - y1));
  if (x1 > x2) {
    distance *= -1; // moving from right to left is negative
  }

  // calculate angle -- the angle at the first point
  double xdiff = std::abs(x1 - x2);
  double ydiff = std::abs(y1 - y2);
  angle = atan(xdiff / ydiff) * 180 / M_PI;
  if (y2 < y1) {
    angle *= -1;
  }

  std::array<double, 2> path = {{ distance, angle }};
  return path;
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

  std::string allowDiagonal;
  std::cout << "\nAllow Diagonal? (Y/n) - ";
  std::cin >> allowDiagonal;

  if (allowDiagonal == "n") {
    std::array<int, 2> path = getShortestPath(firstPointX, firstPointY, secondPointX, secondPointY);
    // print values of path
    std::cout << "\nShortest non-diagonal path: (" << std::get<0>(path) << ", " << std::get<1>(path) << ")\n";
  } else {
    std::array<double, 2> path = diagonalPath(firstPointX, firstPointY, secondPointX, secondPointY);
    // print values of path
    std::cout << "\nShortest diagonal path: length of " << std::get<0>(path) << ", at " << std::get<1>(path) << " degrees.\n";
  }

  return 0;
}
