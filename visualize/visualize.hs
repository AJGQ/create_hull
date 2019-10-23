module Main where

import Render
import MyData
import Logic
import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game

main :: IO ()
main = play (InWindow "visualize" (scrWidth, scrHeight) (0,0)) black fps vizInit showViz handler update 
