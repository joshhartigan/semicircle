-- The Collatz sequence takes in a number, and either
-- divides by 2 if it is even, or
-- multiplies it by 3 and adds 1 if it is odd.
-- The famous Collatz conjecture asks whether the sequence,
-- from any positive initial value, will reach 1.

-- a guard expression is used for the 'collatz' variable,
-- used for finding the next number in a sequence. This is
-- neater than if / else if.
collatz :: Int -> Int
collatz n
    | even n = n `div` 2
    | otherwise = 3 * n + 1

-- another guard expression, this time for the variable that
-- generates whole sequences. it is recursive, and takes 
-- advantage of the 'collatz' variable too.
cltzList :: Int -> [Int]
cltzList n
    | n <= 0 = error "conjecture.cltzList: The number must be positive."
    | n == 1 = [1]
    | otherwise = n:cltzList (collatz n) -- else, recursive-call
