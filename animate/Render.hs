module Render where

import MyData
import Graphics.Gloss

show_action :: (Point,Point)-> Picture
show_action (p0,p1)      
                | p0 == p1 = Translate (fst p0) (snd p0) . Color orange . (\d -> ThickCircle (d/2) d) $ 5
                | otherwise = Color orange $ Line [p0, p1]


showViz :: Viz -> Picture
showViz (Viz ps o a _) = Pictures $ pps ++ po ++ pa
    where
        pps = map (\(x,y) -> Translate x y pp) ps
        pp = Color white . (\d -> ThickCircle (d/2) d) $ 5
        pa = map show_action a
        po = map (\(p1,p2) -> Color (greyN 0.3) $ Line [p1, p2]) o

