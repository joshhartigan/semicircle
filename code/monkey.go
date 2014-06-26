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
    // if item is number
    if num, err := strconv.Atoi(item); err == nil {
        return float32(num)
    }
    return variables[item]
}

func operate(operands []string, op string) float32 {
    var result float32 = 0
    // o = index in operands[]
    for o := 0; o < len(operands); o++ {
        if op == "+" {
            if o == 0 {
                result = getvalue(operands[0])
            } else {
                result += getvalue(operands[o])
            }
        } else if op == "-" {
            if o == 0 {
                result = getvalue(operands[0])
            } else {
                result -= getvalue(operands[o])
            }
        } else if op == "*" {
            if o == 0 {
                result = getvalue(operands[0])
            } else {
                result *= getvalue(operands[o])
            }
        } else if op == "/" {
            if o == 0 {
                result = getvalue(operands[0])
            } else {
                result /= getvalue(operands[o])
            }
        } else {
            return 0.0
        }
    }
    return result
}

var x, y int64 // these will be assigned to function params
var xerr, yerr error
func main() {
    variables = make(map[string]float32)
    lines := openfile(os.Args[1])
    for lineNumber, line := range lines {
        words := strings.Split(line, " ")
        operands := 0 // count of numbers that the operation will be applied to
        for _, word := range words {
            if _, err := strconv.Atoi(word); err == nil {
                operands += 1
            }
        }
        // line needs to end in ';' or ': varName' to be correct
        if len(words) >= operands + 2 {
            if words[operands + 1] == ";" {
                fmt.Println(operate(words[1:operands+1], words[0]))
            } else if words[operands + 1] == ":" {
                fmt.Println("var", words[operands + 2], "=", operate(words[1:operands+1], words[0]))
                variables[words[operands + 2]] = operate(words[1:operands+1], words[0])
            }
        } else if len(words) < 0 && len(words) < operands + 2 {
            fmt.Println("error: not enough arguments at line", lineNumber)
        }
    }
}

