module MyData where

import Graphics.Gloss

out_file :: FilePath
out_file = "points.out"

scrWidth :: Num a => a
scrWidth = 900

scrHeight :: Num a => a
scrHeight = 600

fps :: Num a => a
fps = 30

type Action = [(Point, Point)]
data Viz = Viz [Point] Action Action [Action]

vizInit :: [Point] -> [Action] -> Viz
vizInit ps as = Viz ps [] [] as
