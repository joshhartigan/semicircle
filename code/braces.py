#!/usr/bin/python

import sys

source = open( sys.argv[1], "r" )
output = open( sys.argv[1].replace(".braces", ".py"), "w" )

for line in source.readlines():
    newline = ""

    if line.isspace() and "\n" in line:
        newline = "\n"

    if line[ len(line) - 2 ] == ";":
        newline = line.replace(";", "")

    elif line[ len(line) - 2 ] == "{":
        newline = line.replace("{",":")

    # remove space before colon
    if ":" in newline and newline[ newline.index(":") - 1 ] == " ":
        newline = newline.replace(" :", ":")


    output.write(newline)
