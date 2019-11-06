module Render where

import MyData
import Graphics.Gloss

showViz :: Viz -> IO Picture
showViz (Viz ps) = return $ Pictures pps
    where
        pps = map (\(x,y) -> Translate x y pp) ps
        pp = Color red . (\d -> ThickCircle (d/2) d) $ 5


