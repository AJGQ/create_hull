module MyData where

import Graphics.Gloss

scrWidth :: Num a => a
scrWidth = 900

scrHeight :: Num a => a
scrHeight = 600

fps :: Num a => a
fps = 30

data Viz = Viz [Point]

vizInit :: [Point] -> Viz
vizInit ps = Viz ps
