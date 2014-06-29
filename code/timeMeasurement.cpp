// Author: Josh Hartigan (github.com/joshhartigan)
// Description: This program takes x number of seconds as
//              input, and shows how many hours and minutes
//              are in that many seconds.

#include <iostream>

int main() {
    int seconds;
    std::cout << "How many seconds? - ";
    std::cin >> seconds;

    int minutes = seconds / 60;
    seconds -= seconds - (seconds % 60);
    int hours = minutes / 60;
    minutes -= minutes - (minutes % 60);

    std::cout << hours   << " hours;\n"
              << minutes << " minutes;\n"
              << seconds << " seconds;\n";

    return 0;
}
