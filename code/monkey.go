package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// error management
func check(e error) {
	if e != nil {
		panic(e)
	}
}

func readFile(filename string) (lines []string) {
	// safely open file
	source, err := os.Open(filename)
	defer source.Close()
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
func getValue(item string) float32 {
	// if item is number
	if num, err := strconv.ParseFloat(item, 32); err == nil {
		return float32(num)
	}
	return variables[item]
}

func operate(operands []string, op string) (result float32) {
	result = getValue(operands[0])
	// o = index in operands[]
	for _, o := range operands[1:] {
		switch op {
		case "+":
			result += getValue(o)
		case "-":
			result -= getValue(o)
		case "*":
			result *= getValue(o)
		case "/":
			result /= getValue(o)
		default:
			return 0.0
		}
	}
	return
}

var x, y int64 // these will be assigned to function params
var xerr, yerr error

func main() {
	variables = make(map[string]float32)
	lines := readFile(os.Args[1])
	for lineNumber, line := range lines {
		words := strings.Split(line, " ")
		operands := 0 // count of numbers that the operation will be applied to
		for _, word := range words {
			if _, err := strconv.Atoi(word); err == nil {
				operands += 1
			} else if _, in := variables[word]; in {
				operands += 1
			}
		}
		// line needs to end in ';' or ': varName' to be correct
		if len(words) >= operands+2 {
			if words[operands+1] == ";" {
				fmt.Println(operate(words[1:operands+1], words[0]))
			} else if words[operands+1] == ":" {
				fmt.Println("var", words[operands+2], "=", operate(words[1:operands+1], words[0]))
				variables[words[operands+2]] = operate(words[1:operands+1], words[0])
			} else {
				fmt.Println("error: missing line terminator @", lineNumber)
			}
		} else if len(words) < 0 && len(words) < operands+2 {
			fmt.Println("error: not enough arguments @", lineNumber)
		}
	}
}
