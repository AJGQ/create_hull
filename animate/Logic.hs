module Logic where

import MyData
import Graphics.Gloss.Interface.IO.Interact
import System.Process (callCommand)
import System.Exit (exitSuccess)

show_point :: Point -> String
show_point (x, y) = show (round x) ++ " " ++ (show $ round y)

show_points :: [Point] -> String
show_points = foldr (\p -> \s -> ((show_point p)++"\n"++s) ) ""

handler :: Event -> Viz -> Viz
handler (EventKey (Char 'n') Up _ _) v@(Viz _ _ _ []) = v
handler (EventKey (Char 'n') Up _ _) (Viz ps o a (a':as)) = Viz ps (o++a) a' as
handler e v = v 

update :: Float -> Viz -> Viz
update = const id 
