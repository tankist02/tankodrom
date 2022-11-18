--apply' :: (Int a) => a -> a
apply' a b = sum $ filter (<a) $ map (*2) [1..b]

func = map ($ 3) [(1 +), (2 *)]

compose = (negate . sum . tail) [1..5]

comp = sum . replicate 5 $ max 1 2

