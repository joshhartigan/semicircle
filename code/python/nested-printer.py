#!/usr/bin/env python

def print_nested(li):
    for elem in li:
        if isinstance(elem, list):
            print_nested(elem)
        else:
            print elem

# test
print_nested(
    [1, 2, 'hello', [5, 8, [9, 1]], True, 'j', ['g', 'o', 'o'], 0]
)
