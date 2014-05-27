package main

/**
 * The 'fmt' package enables formatted input-output,
 * similar to C's 'stdio.h' or C++'s 'iostream'
 * libraries.
 * I think it stands for 'format'.
 */
import "fmt"

func main() {
    // using := for assignment can be used instead
    // of the 'var' keyword, with implicit typing
    anArray := []int{33, 10, 7, 94, 7, 2, 6, 18, 3} // arrays are fixed-length
    /**
     * The fmt package's Println function works like Java's
     * System.out.println function. However, where multiple
     * parts of an output would be formatted in Java as such
     *           println("unsorted" + anArray);
     * , in Go they are seperated by a comma, as shown below:
     */
    fmt.Println("unsorted: ", anArray)
    bubblesort(anArray)
    fmt.Println("sorted:   ", anArray)
}

/**
 * A way that Go is different from other C-like languages can
 * be seen here: the type of the parameter comes after the
 * name:
 */
func bubblesort(a []int) {
    // for loops do not require exit condiions:
    for items := len(a)-1; ; items-- {
        change := false
        for index := 0; index < items; index++ {
            if a[index] > a[index+1] {
                // variables are easily swapped:
                a[index], a[index+1] = a[index+1], a[index]
                change = true
            }
        }
        /**
         * Something that is shown a few times in this program
         * is that if statements and for loops don't need parentheses
         * for the header, as they would do in other languages such as
         * Java or C. Instead, the statements and expressions are just
         * followed by an open-brace. This is slightly similar to python's
         * formatting, with the exception of python's significant whitespace
         * and colons rather than braces.
         */
        if !change {
            break
        }
    }
}
