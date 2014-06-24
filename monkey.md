monkey.go is a program that takes a plain text file which includes mathematical instructions, and returns an output.
Here's an example file:

```
+ 22 9
- 100 8 : myVar
+ myVar 4
```

The file will print "31", and "96". Here's a rundown of what's going on with each line:

`+ 22 9` - Monkey executes '22 + 9'. As its result (31) isn't assigned to a variable, it is printed.

`- 100 8 : myVar` - Monkey executes '100 - 8', and stores the result (92) in the variable `myVar`.

`+ myVar 4` - Monkey executes 'myVar + 4', which is 96, and outputs it.

Two further points on Monkey:

* All outputs and variables are 32 bit floating point numbers.
* The current supported operands are '+', '-', '*', and '/'.
