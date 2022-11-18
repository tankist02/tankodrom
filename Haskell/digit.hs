import Data.Char
import Data.List

digitSum :: Int -> Int
digitSum = sum . map digitToInt . show

firstTo40 :: Int -> Maybe Int
firstTo40 n = find (\x -> digitSum x == n) [1..]
