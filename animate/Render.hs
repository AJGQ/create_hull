module Render where

import MyData
import Graphics.Gloss
import Algebra.FloatingPoint as F

showViz :: Viz -> Picture
showViz (Viz ps o a _) = Pictures $ pps ++ po ++ pa
    where
        pps = map (\(x,y) -> Translate x y pp) ps
        pp = Color white . (\d -> ThickCircle (d/2) d) $ 5
        pa = map (\(p1,p2) -> Color orange $ Line [p1, p2]) a
        po = map (\(p1,p2) -> Color (greyN 0.3) $ Line [p1, p2]) o

