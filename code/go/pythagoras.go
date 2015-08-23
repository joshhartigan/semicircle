package main

import (
    "fmt"
    "math"
)

// returns whether or not a, b, and c fit the
// pythagorean theorem - i.e. a^2 = b^2 == c^2
func isPythagorean(a, b, c int) bool {
    x, y, z := float64(a), float64(b), float64(c)
    return (math.Pow(x, 2) + math.Pow(y, 2) == math.Pow(z, 2))
}

// returns sqrt(a^2 + b^2) - the hypotenuse
func getHypotenuse(a, b int) float64 {
    return math.Sqrt(math.Pow(float64(a), 2) + math.Pow(float64(b), 2))
}

func main() {
    fmt.Println(isPythagorean(3, 4, 5)) // -> true
    fmt.Println(isPythagorean(2, 4, 9)) // -> false
    fmt.Println(getHypotenuse(3, 4))    // -> 5
    fmt.Println(getHypotenuse(2, 4))    // -> 4.4721
}
