module Render where

import MyData
import Graphics.Gloss
import Algebra.FloatingPoint as F

showViz :: Viz -> IO Picture
showViz (Viz ps) = return $ Pictures pps
    where
        pps = map (\(x,y) -> Translate x y pp) ps
        pp = Color red . (\d -> ThickCircle (d/2) d) $ 5

square :: Point -> Point -> Picture
square d@(dx,dy) p@(px,py) = Polygon [p, (px+dx, py), (px+dx, py+dy), (px, py+dy)]

