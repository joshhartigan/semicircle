# Same functionality / logic as nextPrime.cpp

def isPrime(num)
  if num <= 1        then false
  elsif num == 2     then true
  elsif num % 2 == 0 then false

  else
    prime = true
    divisor = 3
    max = Math.sqrt num

    while divisor <= max
      if num % divisor == 0 then prime = false end
      divisor += 2
    end

    return prime
  end
end

def nextPrime(start)
  x = start
  while not isPrime x
    x += 1
  end
  return x
end

# tests
puts nextPrime 15 # -> 17
puts nextPrime 48 # -> 53
puts nextPrime 68 # -> 71

