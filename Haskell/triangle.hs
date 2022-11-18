rightTriangles m s = [ (a,b,c) | c <- [1..m], a <- [1..c], b <- [1..a], a^2 + b^2 == c^2, a + b + c == s ]
-- factorial :: Int -> Int
factorial :: Integer -> Integer
-- factorial n = product [1..n]
factorial 0 = 1
factorial n = n * factorial (n - 1)

