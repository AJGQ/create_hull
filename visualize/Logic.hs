module Logic where

import Data.List
import MyData
import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game

handler :: Event -> Viz -> Viz
handler = const id


update :: Float -> Viz -> Viz
update = const id
