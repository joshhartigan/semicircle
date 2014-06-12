#include <string>
#include <algorithm>

using namespace std;

bool palindrome(string s) {
    return equal(s.begin(), s.begin() + s.length() / 2, s.rbegin());
}
