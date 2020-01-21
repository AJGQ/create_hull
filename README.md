# divide\_and\_conquer
Convex hull algorithm

# lib
Library that src/hull.c will use

# src
Source of the main program (hull.c), that given a list of points (one point in each line and x and y coordenates separated by space)
will give: 

- ./hull      : pretty representation of convex hull (counter clockwise polygon)
- ./hull c    : the points given in input and the representation of all steps in the computation of the convex hull

## example
> ./hull < points.in

# visualize
An haskell program that needs:

- ghc: haskell compiler
- gloss: haskell library

That helps you to give points by input of the program and by hand on the graphical interface
when you want to run the convex hull code, just press 's' and it activates animate, so that you
can see steps of the program, one by one.

- press 'q': to exit
- press 's': to activate animate with the chosen points
- mouse click anywhere: to register a point

## example
> ./visualize < points.in

# animate
An haskell program that needs:

- ghc: haskell compiler
- gloss: haskell library

That helps you see all the steps in the computation of the convex hull.

- press 'n': for next step
- press 'p': for previous step
- press ESC: to exit

## example
> ./animate < points.in

