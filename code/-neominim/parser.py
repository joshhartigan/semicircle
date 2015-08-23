#!/usr/bin/env python
# -*- coding: utf-8 -*-
__author__ = "joshhartigan"

import re
from .type import NeoMinimError

def parse(source):
    """ parse string-formatted source code into
    abstract syntax tree. """
    return 

def quote_expand(source):
    if (source[0] == "\""):
        return "(quote " + source[1:] + ")"


def comment_remove(source):
    """ remove '// -> line break' from source """
    return re.sub(r"\/\/.*\n", "\n", source)

def close_parenthesis(source, begin = 0):
    """ with the index 'start' of an opening parenthesis,
    return the matching close parenthesis. """
    assert source[begin] == "("
    index = begin
    open_parentheses = 1
    while open_parentheses > 0:
        index += 1
        if len(source) == index:
            raise NeoMinimError("unmatched parenthesis '%s'" % source[begin:])
        if source[index] == "(":
            open_parentheses += 1
        if source[index] == ")":
            open_brackets -= 1
    return index

def expression_split(source):
    """ split string-formatted source code into
    a list of smaller expressions to be individually
    parsed. """
    tail = source.strip()
    expressions = []
    while tail:
        exp, tail = first_expression(tail)
        expressions.append(exp)
    return expressions

def first_expression(source):
    """ break string-formatted expression into
    [exp, tail], where exp is the first expression,
    and tail is the rest of the original expression. """
    source = source.strip()
    if source[0] == "\"":
        exp, tail = first_expression(source[1:])
        return source[0] + exp, tail
    elif source[0] == "(":
        close = close_parenthesis(source)
        return source[:close + 1], source[close + 1:]
    else:
        # this regex looks for:
        # (start of line) -> (anything except [whitespace, ), or "]
        match = re.match(r"^[^\s)\"]+", source)
