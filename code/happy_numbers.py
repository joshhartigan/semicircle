def getDigits(n):
    digits = []
    for d in str(n):
        digits.append(int(d))
    return digits

def isHappyNumber(n):
    previous = []
    while True:
        digits = getDigits(n)
        digitSquareSum = sum([d ** 2 for d in digits])
        if digitSquareSum == 1:
            return True
        elif digitSquareSum in previous:
            return False
        else:
            n = digitSquareSum
            previous.append(n)

def getHappyNumbers(n, count):
    numbers = []
    iteration = 0
    while iteration < count:
        if isHappyNumber(n):
            numbers.append(n)
            iteration += 1
        n += 1
    return numbers

print (getHappyNumbers( int( input("enter a positive number: ") ), 8))
