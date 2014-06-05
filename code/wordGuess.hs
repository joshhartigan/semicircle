import System.Random (randomRIO)

wordlist = ["house","cat","alarm","program","timetable","clock","orange","friday"]

guess :: String -> String
guess w
    | w == correct = "Correct!"
    | otherwise = "Wrong! Here's a hint: " ++ [hint]
    where
        correct = wordlist !! randomRIO (0, length wordlist)
        hint = correct !! [0..(length correct - 1)] !! randomRIO (0, length [0..length correct - 1])
