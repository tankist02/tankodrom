import Data.List

findKey :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey key xs = foldr (\(k, v) acc -> if key == k then Just v else acc) Nothing xs

findKey' :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey' key xs = foldl (\ acc (k, v) -> if key == k then Just v else acc) Nothing xs

