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
type Present= [Action]
type Future = [Action]
type Past = [Action]
data Viz = Viz [Point] Past Present Future

vizInit :: [Point] -> [Action] -> Viz
vizInit ps as = Viz ps [] [] as
