tell :: (Show a) => [a] -> String
tell [] = "The list is empty"
tell ([x]) = "The list has one element: " ++ show x
tell ([x,y]) = "The list has two elements: " ++ show x ++ " and " ++ show y
tell (x:y:_) = "The list is long, first element: " ++ show x ++ ", second: " ++ show y

add :: (Num a) => [a] -> a
add ([x,y,z]) = x + y + z

mymax :: (Ord a) => a -> a -> a
mymax a b
    | a < b = b
    | otherwise = a

myCompare :: (Ord a) => a -> a -> Ordering
a `myCompare` b
    | a == b = EQ
    | a < b = LT
    | otherwise = GT

getBMI :: Double -> Double -> String
getBMI weight height
    | bmi <= skinny = "skinny"
    | bmi <= normal = "normal"
    | bmi <= fat = "fat"
    | otherwise = "obese"
    where 
        bmi = weight / height ^ 2
        (skinny, normal, fat) = (18.5, 25.0, 30.0)

getBMIs :: [(Double, Double)] -> [Double]
getBMIs xs = [bmi w h | (w, h) <- xs]
    where bmi weight height = weight / height ^ 2

letitbe :: Double -> String -> (Double, String)
letitbe a s = (let x = a in x * 2, let y = s in "Hello, " ++ y)

getBMIs2 :: [(Double, Double)] -> [Double]
getBMIs2 xs = [bmi | (w, h) <- xs, let bmi = w / h ^ 2, bmi > 23.0]

tellList :: [a] -> String
tellList ls = "This is " ++ case ls of 
    [] -> "empty"
    [a] -> "singleton"
    _ -> "long"
    ++ " list"

tellList2 :: [a] -> String
tellList2 ls = "This list is " ++ what ls
    where what [] = "empty"
          what [x] = "one element"
          what _ = "longer than one"

maxim :: (Ord a) => [a] -> a
maxim [] = error "Max of empty list"
maxim [x] = x
maxim (x:xs) = max x (maxim xs)

repl :: Int -> a -> [a]
repl n x 
    | n <= 0 = []
    | otherwise = x : repl(n - 1) x

take2 :: (Num i, Ord i) => i -> [a] -> [a]
take2 n _
    | n <= 0 = []
take2 _ [] = []
take2 n (x:xs) = x : take2(n - 1) xs

rever :: [a] -> [a]
rever [] = []
rever (x:xs) = rever(xs) ++ [x]

rep :: a -> [a]
rep x = x : rep x

zip2 :: [a] -> [b] -> [(a,b)]
zip2 [] _ = []
zip2 _ [] = []
zip2 (x:xs) (y:ys) = (x,y) : zip2 xs ys

mylast :: [a] -> a
mylast [] = error "Empty!"
mylast (x:[]) = x
mylast (x:xs) = mylast xs

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = 
    let smallerOrEqual = [a | a <- xs, a <= x]
        larger = [a | a <- xs, a > x]
    in quicksort smallerOrEqual ++ [x] ++ quicksort larger

multThree :: (Num a) => a -> a -> a -> a
multThree a b c = a * b * c

