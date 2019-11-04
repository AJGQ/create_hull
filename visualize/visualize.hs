module Main where

import Render
import MyData
import Logic
import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game


read_points :: String -> [Point]
read_points = map ((\[x,y] -> (x,y)) . map read) . map words . lines

main :: IO ()
main = getContents >>= (\ps -> play (InWindow "visualize" (scrWidth, scrHeight) (0,0)) black fps (vizInit ps) showViz handler update) . read_points
