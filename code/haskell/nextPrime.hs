factors :: Int -> [Int]
factors n = [i | i <- [1..n], (mod n i) == 0]

isPrime :: Int -> Bool
isPrime n = n > 2 && tail (factors n) == [n]

nextPrime :: Int -> Int
nextPrime n = head [i | i <- [n..], isPrime i]

