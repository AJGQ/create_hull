module Logic where

import MyData
import Graphics.Gloss.Interface.IO.Interact

handler :: Event -> Viz -> Viz
handler (EventKey (MouseButton LeftButton) Up _ p) (Viz ps) = Viz (p:ps)
handler e v = v 

update :: Float -> Viz -> Viz
update = const id 

