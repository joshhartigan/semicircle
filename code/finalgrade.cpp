/* An exercise from Google's C++ course:
 * "Write a program that will compute your final grade for a programming
 * course you are taking."
 * The grading scheme is: 40% Assignments; 15% Midterm; 35% Final Exam;
 * 10% Class Participation.
 */
#include <string>
#include <iostream>

using namespace std;

int getscore(string scorename) {
    int score;
    cout << scorename;
    cin >> score;
    return score;
}

float allscores() {
    int first    = getscore("First assignment score: ");
    int second   = getscore("Second assignment score: ");
    int third    = getscore("Third assignment score: ");
    int fourth   = getscore("Fourth assignment score: ");
    int midterm  = getscore("Midterm exam score: ");
    int final    = getscore("Final exam score: ");
    int particip = getscore("Participation score: ");

    int assignments = (first + second + third + fourth) / 4;
    return (assignments * 0.4) + (midterm * 0.15) + (final * 0.35) + (particip * 0.1);
}

int main() {
    float finalgrade = allscores();
    cout << "The final grade is: " << finalgrade << endl;

    return 0;
}

