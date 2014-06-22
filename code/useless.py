def printNum(n):
    return "".join([str(len(str(d) * int(d))) for d in list(str(n))])

print printNum(2014)
print printNum(1135)
print printNum(2048)
