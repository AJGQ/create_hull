module Render where

import Graphics.Gloss
--import Graphics.Gloss.Data.Picture
import MyData

showViz :: Viz -> Picture
showViz (Pop l p) = p <> (Pictures $ map (\(x,y) -> Scale x y $ Circle 10) l)
showViz (Viz f ll p) = p <> (Pictures $ map polygon (ll!!f))
showViz (Init l) = Pictures l
