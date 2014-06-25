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

func operate(operands []string, op string) float32 {
    result := 0
    // o = index in operands[]
    for o := 0; o < len(operands); o++ {
        if op == "+" {
            if o == 0 { result := operands[0] }
            else {
                result += operands[o]
            }
        } else if op == "-" {
            if o == 0 { result := operands[0] }
            else {
                result -= operands[o]
            }
        } else if op == "*" {
            if o == 0 { result := operands[0] }
            else {
                result *= operands[o]
            }
        } else if op == "/" {
            if o == 0 { result := operands[0] }
            else {
                result /= operands[o]
            }
        }
    }
    return float32(result)
}

var x, y int64 // these will be assigned to function params
var xerr, yerr error
func main() {
    variables = make(map[string]float32)
    lines := openfile(os.Args[1])
    for _, line := range lines {
        words := strings.Split(line, " ")
        // expressions are printed
        if words[len(words)-1] == ";" {
           fmt.Println(operate(, words[0]))
        } else {
            // variable assignment
            if words[len(words)-2] == ":" {
                variables[words[len(words)-1]] = operate(words[1], words[2], words[0])
            }
        }
    }
}

