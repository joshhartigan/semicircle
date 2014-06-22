def printNum(n):
    result = ""
    ns = str(n)
    result += "".join([str(len(str(d) * int(d))) for d in list(ns)])
    return result

print printNum(2014)
print printNum(1135)
print printNum(2048)
