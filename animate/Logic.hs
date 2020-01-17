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
handler (EventKey (Char 'n') Up _ _) (Viz ps pas pras ([l]:fas)) = Viz ps pas ([l]:pras) fas
handler (EventKey (Char 'n') Up _ _) (Viz ps pas (a1:a2:pras) (fa:fas)) = Viz ps (a2:a1:pas) (fa:pras) fas
handler (EventKey (Char 'p') Up _ _) v@(Viz _ [] _ _) = v
handler (EventKey (Char 'p') Up _ _) (Viz ps pas ([l]:pras) fas) = Viz ps pas pras ([l]:fas)
handler (EventKey (Char 'p') Up _ _) (Viz ps (a2:a1:pas) (pra:pras) fas) = Viz ps pas (a1:a2:pras) (pra:fas)
handler e v = v 

update :: Float -> Viz -> Viz
update = const id 
