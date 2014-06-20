-- In this program, we will implement our own
-- version of Haskell's 'take' function.
-- it is a function that returns a certain
-- number of elements from any list.
-- here's an example of the original:

take 4 [4,8,1,3,5,9,6,7,2] -- This will return [4,8,1,3]

-- Now, here is my own implementation:
-- it takes a number, and an Ord (a value that can be
-- ordered, like a list) as input, and returns a
-- list.
take' :: (Num i, Ord i) => i -> [a] -> [a]
-- Below, the '_' name is used for parameters. This is
-- a valid variable name, and works just the same as
-- a name like 'x', but in convention it represents a
-- non-important variable in pattern matching.
take' n _
    -- This guard has no 'otherwise' pattern. Therefore,
    -- if it is false, the function will go straight to
    -- the next pattern (namely "take' _ []")
    | n <= 0 = [] -- If the function's called and n is 
                  -- less than or equal to 0, there are
                  -- no values in the list to return.
take' _ [] = []   -- There are no values in an empty list,
                  -- so the function should always return
                  -- an empty list when given one.
-- In this final pattern, the list parameter is broken into
-- a head (x) and a tail (xs). Returning 'n' elements from
-- a list can be done by creating a list with 'x' as its
-- first element, and 'n - 1' elements from 'xs' as its
-- tail. Therefore, this is a recursive function.
take' n (x:xs) = x : take' (n - 1) xs
