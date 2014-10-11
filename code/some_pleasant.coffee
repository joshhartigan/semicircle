# Constant strings to print on certain error
SYNTAX_ERROR = 'unrecognised syntax: '

# Lexical matchers
isString = (str) -> str[0] == '\'' and str[str.length - 1] == '\''

isNumber = (str) -> not isNaN(str)

isIdentifier = (str) -> /// ^
  [^\s(),']   # anything but whitespace, '(', ')', ',', or '''.
  +           # one or more of the previous
  $           # end of word
///.exec str

isCall = (str) -> str[0] == '(' and str[str.length - 1] == ')'

parseExpr = (expr) ->
  expr = trim expr

  syntax = {
    type: 'value', value: expr.substring(0, expr.length - 1)
  } if isString expr

  syntax = {
    type: 'value', value: Number(expr)
  } if isNumber expr

  syntax = {
    type: 'identifier', value: expr
  } if isIdentifier expr

  return parseFunctionCall expr if isCall expr

  if not (isString(expr) or isNumber(expr) or isIdentifier(expr) or isCall(expr))
    console.log(SYNTAX_ERROR + expr)
