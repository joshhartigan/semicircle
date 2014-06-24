package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
)

// error management
func check(e error) {
    if e != nil {
        panic(e)
    }
}

func openfile(filename string) (lines []string) {
    // safely open file
    source, err := os.Open(filename)
    check(err)

    scanner := bufio.NewScanner(source)
    // equivalent to a while loop
    for scanner.Scan() {
        lines = append(lines, scanner.Text())
    }

    return
}

var variables map[string]float32

// determine whether a token is a variable reference or
// an integer literal, and return it.
func getvalue(item string) float32 {
    if num, err := strconv.Atoi(item); err == nil {
        return float32(num)
    }
    return variables[item]
}

func operate(operandA, operandB string, op string) float32 {
    if op == "+" {
        x, y := getvalue(operandA), getvalue(operandB)
        return float32(x + y)
    } else if op == "-" {
        x, y := getvalue(operandA), getvalue(operandB)
        return float32(x - y)
    } else if op == "*" {
        x, y := getvalue(operandA), getvalue(operandB)
        return float32(x * y)
    } else if op == "/" {
        x, y := getvalue(operandA), getvalue(operandB)
        var z float32 = float32(x) / float32(y)
        return z
    } // else:
    return 0
}

var x, y int64 // these will be assigned to function params
var xerr, yerr error
func main() {
    variables = make(map[string]float32)
    lines := openfile(os.Args[1])
    for _, line := range lines {
        words := strings.Split(line, " ")
        if len(words) == 3 {
            fmt.Println(operate(words[1], words[2], words[0]))
        } else if len(words) == 5 {
            if words[3] == ":" {
                variables[words[4]] = operate(words[1], words[2], words[0])
            }
        }
    }
}
