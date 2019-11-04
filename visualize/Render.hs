module Render where

import MyData
import Graphics.Gloss
import Algebra.FloatingPoint as F

showViz :: Viz -> Picture
showViz (Viz ps) = Pictures pps
    where
        pps = map (\(x,y) -> Translate x y pp) ps
        pp = Color red . (\d -> ThickCircle (d/2) d) $ 5

square :: Point -> Point -> Picture
square d@(dx,dy) p@(px,py) = Polygon [p, (px+dx, py), (px+dx, py+dy), (px, py+dy)]

{-
showButton :: Button -> Picture
showButton (Button s d@(dx,dy) p@(px,py)) = Pictures [sq, txt]
    where
        sq = Color orange $ square d p
        txt = Color white . Translate px py . Scale (dx/txtw) (dy/txth) $ Text s
        txtw = 500--F.scale (length s) txth/2
        t. Scale (dx/txtw) (dy/txth) xth = 105
-}
