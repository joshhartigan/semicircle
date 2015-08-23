package main

import (
    "fmt"
    "math"
)

func power(x, y int) (result int) {
    result = 1
    for i := 0; i < y; i++ {
        result *= x
    }
    return
}

// polish notation calculation function
func solve(operation string, x int, y int) int {
    switch (operation) {
        default: return x

        // basic arithmetic functions
        case "+": return x + y
        case "-": return x - y
        case "*": return x * y
        case "/": return x / y

        // higher level functions
        case "pow": return power(x, y)
        case "sqrt": return int(math.Sqrt(float64(x)))
    }
}

func main() {
    fmt.Println("'+ 34 16': ", solve("+",34,16))
    fmt.Println("'* 6  51': ", solve("*",6 ,51))
    fmt.Println("'pow 6 4': ", solve("pow",6,4))
    fmt.Println("'sqrt 25': ", solve("sqrt",25,0))
}
