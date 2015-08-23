#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    } else if (num == 2) {
        return true;
    } else if (num % 2 == 0) {
        return false;
    } else {
        bool prime = true;
        int divisor = 3;
        // get square root as upper limit
        double doubleNum = static_cast<double>(num);
        int max = static_cast<int>(sqrt(doubleNum) + 1);

        while (divisor <= max) {
            if (num % divisor == 0) {
                prime = false;
            }
            divisor += 2;
        }
        return prime;
    }
}

int nextPrime(int start) {
    int x = start;
    while (!isPrime(x)) {
        x += 1;
    }
    return x;
}

int main() {
    cout << nextPrime(15) << endl; // -> 17
    cout << nextPrime(48) << endl; // -> 53
    cout << nextPrime(68) << endl; // -> 71
}
