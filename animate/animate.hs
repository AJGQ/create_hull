module Main where

import Render
import MyData
import Logic
import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game

split :: Char -> String -> [String]
split _ [] = [""]
split c (s:ss) = if s == c
                    then "":aux
                    else  (s:x):xs
    where aux@(x:xs) = split c ss

read_points :: String -> [Point]
read_points = map ((\[x,y] -> (x,y)) . map read) . map words . lines

read_actions :: String -> [Action]
read_actions = 
    map (
        map (
            list2pair . 
            map( 
                list2pair . 
                ( map read . words)
            ) . 
            split ','
        ) . 
        split ';'
    ) . 
    lines
    where list2pair [x,y] = (x,y)

read_all :: String -> ([Point], [Action])
read_all = (\[x,y] -> (read_points x, read_actions $ tail y)) . split '$'

main :: IO ()
main = getContents >>= (\(ps, as) -> play (InWindow "visualize" (scrWidth, scrHeight) (0,0)) black fps (vizInit ps as) showViz handler update) . read_all
