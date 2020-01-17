module Logic where

import MyData
import Graphics.Gloss.Interface.IO.Interact
import System.Posix.Process (forkProcess)
import System.Process (callCommand)
import System.Exit (exitSuccess)

show_point :: Point -> String
show_point (x, y) = show (round x) ++ " " ++ (show $ round y)

show_points :: [Point] -> String
show_points = foldr (\p -> \s -> ((show_point p)++"\n"++s) ) ""

handler :: Event -> Viz -> IO Viz
handler (EventKey (MouseButton LeftButton) Up _ p) (Viz ps) = return $ Viz (p:ps)
handler (EventKey (Char 's') Up _ _) (Viz ps) = 
    writeFile out_file (show_points ps) 
    >>= ( const $ callCommand ("../src/hull c < " ++ out_file ++ " > ../animate/" ++ in_file))
    >>= ( const $ forkProcess ( callCommand ("../animate/animate < ../animate/" ++ in_file)))
    >>= ( const $ exitSuccess ) 
    >>= ( const $ return $ Viz ps)
handler (EventKey (Char 'q') Up _ _) _ = exitSuccess
handler e v = return v 

update :: Float -> Viz -> IO Viz
update = const return  

