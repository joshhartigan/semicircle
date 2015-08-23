package main

import (
    "fmt"
    "math"
)

/**
 * This function is given a named return
 * variable, the int 's'. Because of this,
 * we only need to type 'return' at the
 * end of the function, rather than
 * 'return s'.
 */
func problem1() (s int) { // sum of all multiples of 3 and 5 below 1000
    // := operator for inferred type
    for i := 0; i < 1000; i++ {
        if i % 3 == 0 || i % 5 == 0 {
            s += i
        }
    }
    return
}

func sumOfSquares(iter float64) int {
    sum := float64(0)
    for i := float64(0); i <= iter; i++ {
        sum += math.Pow(i, 2)
    }
    return int(sum)
}

func squareOfSum(iter int) int {
    sum := 0
    for i := 0; i <= iter; i++ {
        sum += i
    }
    return int(math.Pow(float64(sum), 2))
}

func problem6() int { // difference between sum of the squares of 1..100, and
                      // the square of the sum of 1..100
    difference := squareOfSum(100) - sumOfSquares(100)
    return difference
}

func main() {
    fmt.Println(problem1())
    fmt.Println(problem6())
}
