package main

func palindrome(s string) bool {
    lastChar   := len(s) - 1
    middleChar := len(s) / 2

    for i := 0; i < middleChar; i++ {
        if s[i] != s[lastChar-i] {
            return false
        }
    }

    return true
}
