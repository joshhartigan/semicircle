package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
)

var variables map[string]int

// determine whether a token is a variable reference or
// an integer literal, and return it.
func getvalue(item string) int {
    if num, err := strconv.Atoi(item); err == nil {
        return num
    }
    return variables[item]
}

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

var x, y int64 // these will be assigned to function params
var xerr, yerr error
func main() {
    lines := openfile(os.Args[1])
    for _, line := range lines {
        words := strings.Split(line, " ")
        // convert function parameters to integer types and operate on them
        if words[0] == "+" {
            x, y := getvalue(words[1]), getvalue(words[2])
            fmt.Println(x + y)
        } else if words[0] == "-" {
            x, y := getvalue(words[1]), getvalue(words[2])
            fmt.Println(x - y)
        } else if words[0] == "*" {
            x, y := getvalue(words[1]), getvalue(words[2])
            fmt.Println(x * y)
        } else if words[0] == "/" {
            x, y := getvalue(words[1]), getvalue(words[2])
            var z float32 = float32(x) / float32(y)
            fmt.Println(z)
        }
    }
}
