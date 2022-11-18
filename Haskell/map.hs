import qualified Data.Map as Map
import qualified Data.Char as Ch

isDigit :: Char -> Bool
isDigit c = c `elem` "0123456789"

str2dig :: String -> [Int]
str2dig = map Ch.digitToInt . filter isDigit

phoneBookToMap :: (Ord k) => [(k,String)] -> Map.Map k String
phoneBookToMap xs = Map.fromListWith add xs
    where add s1 s2 = s1 ++ ", " ++ s2

phoneBookToMap' :: (Ord k) => [(k,a)] -> Map.Map k [a]
phoneBookToMap' xs = Map.fromListWith (++) $ map (\(k,v) -> (k,[v])) xs

