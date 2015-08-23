/* #include:
 * In C++, many tools and facilities are part of the standard library.
 * The core language is available to all programs, but parts of the standard
 * library must be explicitly asked for when use of them is desired.
 * This is done with an #include directive. These usually appear at the beginning
 * of the program. In the line below this comment, the line
 *
 * #include <iostream>
 * 
 * is written. The name 'iostream' means the part of the standard library that 
 * allows streamed, or sequential, input-output. As it appears in an include
 * directive, and is enclosed in angular brackets, it refers to a Standard Header
 * in the standard C++ library.
 */
#include <iostream>   // sequential input-output
#include <string>     // used for strings and string literals of characters

/* The main() function:
 * Every C++ program must contain a main function. It is the first function of a
 * program that is run by a C++ implementation. The reason the main function has
 * a return type of int [Integer], which is compulsory, is so that it can return the
 * value of 0 if a program ran succesfully.
 */
int main() {
    // << is the output operator. "hello, world" is passed to std::cout from the iostream package,
    // followed by std::endl (end line).
    std::cout << "hello, world" << std::endl;
    /* Escape characters can be used in string literals.
     * Some basic useful examples are:
     *     \n    - newline character
     *     \t    - tab character
     *     \b    - backspace character
     *     \"    - double quotes
     *     \'    - single quote
     *     \\    - backslash
     * Below they are used, alongside repeated usage of the std::cout and std::endl names.
     */
    std::cout << "this (\") is a quote, and this (\\) is a backslash." << std::endl;

    

    // here, a value of 0 is returned to end the program.
    return 0;
}
