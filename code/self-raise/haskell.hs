selfRaise :: [a] -> [a]
selfRaise coll =
  [n ^ n | n <- a]

-- test
putStrLn selfRaise [1, 8, 2, 6, 4, 5]
