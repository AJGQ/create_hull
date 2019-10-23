module MyData where

import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game

data Viz = Pop [Point] Picture | Viz Int [[Path]] Picture | Init [Picture]

fps :: Int
fps = 30

scrWidth :: Num a => a
scrWidth = 640

scrHeight :: Num a => a
scrHeight = 480

button :: Point -> Point -> String -> Picture
button (x1,y1) (x2,y2) s = Color white $ ( Scale (x2-x1) (y2-y1) $
    Polygon [ (0,0), (1,0), (1,1), (0,1) ] ) <> ( Text s )

vizInit :: Viz
vizInit = Init [ button (0,100) (100,0) "sup"
               , button (200,300) (300,200) "sup2"
               ]
