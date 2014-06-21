package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
)

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
        // convert function parameters to integer types
        if words[0] == "+" || words[0] == "-" || words[0] == "*" || words[0] == "/" {
            x, xerr = strconv.ParseInt(words[1], 10, 0)
            check(xerr)
            y, yerr = strconv.ParseInt(words[2], 10, 0)
            check(yerr)
        }
        if words[0] == "+" {
            fmt.Println(x + y)
        } else if words[0] == "-" {
            fmt.Println(x - y)
        } else if words[0] == "*" {
            fmt.Println(x * y)
        } else if words[0] == "/" {
            fmt.Println(x / y)
        }
    }
}
