#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// return a random integer from 1 to 5:
int rand5() {
    return rand() % 5 + 1;
}

// implement rand7() using rand5();
int rand7() {
    // declare x's initial value to be > 7
    int x = 8;
    while (x > 7) {
        /**
         * Let's split this assignment
         * into multiple parts:
         *
         * x = 5 * rand5();
         *
         * With the line above, we could have
         * any number from [5, 10, 15, 20, 25] -
         * the first 5 multiples of 5.
         *
         * [5 or 10 or 15 or 20 or 25] + rand5() - 5;
         *
         * With the first 5 multiples of 5, this table
         * shows how they're affected by adding rand5()
         * and subtracting 5:
         *
         * 5  ==>  6  7  8  9 10; (-5) ==> 1  2  3  4  5
         * 10 ==> 11 12 13 14 15; (-5) ==> 6  7  8  9  10
         * 15 ==> 16 17 18 19 20; (-5) ==> x > 7
         * 20 ==> 21 22 23 24 25; (-5) ==> x > 7
         * 25 ==> 26 27 28 29 30; (-5) ==> x > 7
         *
         * (With cases from 15 -> 25, all 'x's are larger than
         * 7, and therefore useless.)
         */
        x = 5 * rand5() + rand5() - 5;
    }
    return x;
}

int main() {
    srand(time(NULL));

    cout << "rand5(): " << rand5() << endl;
    cout << "rand7(): " << rand7() << endl;
    return 0;
}
