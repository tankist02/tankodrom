elem' :: (Eq a) => a -> [a] -> Bool
elem' y xs = foldr (\x acc -> if x == y then True else acc) False xs

maximum' :: (Ord a) => [a] -> a
maximum' = foldl1 max

maximum2 :: (Ord a) => [a] -> a
maximum2 = foldr1 max

reverse' :: [a] -> [a]
reverse' = foldl (\acc x -> x : acc) []

reverse'' :: [a] -> [a]
reverse'' = foldr (\x acc -> acc ++ [x]) []

count' :: (Num a) => [a] -> a
count' = foldl (\ acc _ -> acc + 1) 0

chain' :: (Num a) => [a] -> [a]
chain' = scanl (\ acc _ -> acc + 1) 0

sum' :: (Num a) => [a] -> a
sum' = foldl (\ acc x -> acc + x) 0
