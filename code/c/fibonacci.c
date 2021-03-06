/**
 * Include the STandarD Input Output library, stdio.h.
 * This gives access to multiple functions, but in this
 * program is only used for its printf() function, used
 * for outputting formatted strings to stdout.
 */
#include <stdio.h>

/**
 * Here the fib() function is declared, and told to take
 * one parameter: an integer 'n'.
 */
int fib(int n) {
    /**
     * The if statement checks for the truth of 'n < 2'.
     * If the statement is true, the statement/s inside the
     * if block (in this case, 'return n') will be executed.
     * Otherwise, one of two things will happen: statements
     * inside an else block will occur (this is the situation
     * the code below shows), or if there is not an else block,
     * the statement will finish and the program will continue.
     */ 
    if (n < 2) {
        return n; // returning 'n' simply 'quits' the function
                  // and hands over the value of 'n' to the rest
                  // of the program.
    } else {
        /**
         * In this else block, rather than returning the value of 'n',
         * we return a new value, generated by recursion. We return
         * the value of 'n - 1' - when passed as an argument in the
         * fib() function, in addition to the value of 'n - 2', when
         * passed as an argument in the fib() function.
         */ 
        return fib(n - 1) + fib(n - 2);
    } // the scope of the if|else ends.
} // the scope of fib() ends.

/**
 * Declare the main function - all C programs must have
 * a main function. The one in this specific program is
 * simply used to call our fib() function multiple times.
 */
int main() {
    /**
     * The two lines below are the header of the for loop.
     * The loop uses the integer variable 'i' to call the
     * fib() function multiple times. Seperate parts of the
     * loop will be explained as they appear.
     */ 
    int i = 0; // Here, the 'i' variable for the loop is declared.
    for (i = 0; i < 10; i++) { /**
                                * 'i' is assigned to 0, the loop is told to
                                * check the truth of 'i < 10' (and end
                                * when the statement returns false), and
                                * it's instructed to iterate 'i' at the end
                                * of each looping - 'i++'.
                                */
        printf("Fibonacci Number #%d: %d\n", i, fib(i)); // here, the value of 'fib(i)' is simply
                                                         // printed to stdout, with a small bit of
                                                         // formatting.
    } // the scope of the for loop ends.
} // the scope of main() ends.
