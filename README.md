# Systems Final Project
## Battleship

## Members
  * Tim Marder, Sophia Xia, Anand Idris (Period 4)

## Description
  * A Battleship game in which two terminals can connect to each other the various moves that each side made for each turn.
  * Each player will have, at all times, access to the stats of each ship that they have, an ASCII grid of their own board, and an ASCII grid of the opponent's board (blanked out, of course).

## Libraries
  * No external libraries needed.

## How to run
  * Please cd into the "sockets" directory, and run "make".  
  * Open ./server in that terminal, and then open a second terminal (in the same computer) and open ./client.
  * Moves can be inputted as any standard grid coordinate system for Battleship.  Examples: "A1","B7","G4"

## Devlog


### December 28 (Tim, Sophia, Anand)
  * Project made.

### January 10 (Sophia)
  * IP Address connection, in an attempt to have two DIFFERENT computers connect.  While we could get one computer to connect to itself, sockets could not be configured such that two computers would be able to communicate with one another.

### January 11 (Tim & Anand)
  * Board generation, in which a 10x10 grid was made detailing which coordinate could be plain water, which is a unhit ship, what is hit, and what is a miss.

### January 14 (Anand)
  * Coordinates: Read a file that gives you coordinates, turn this into an array of coordinates that our program can use.

### January 15 (Sophia)
  * Socket connection works, but only if the other computer fidgets with their IP address.

### January 16 (Tim)
  * Board generation, but this time it reads the instructions you give it through the alpha_coordinates.txt file.

### January 17 (Sophia & Anand)
  * Hit detection, writing a new file to potentially store moves in order to have rudimentary saving.  (THIS FEATURE IS SCRAPPED, THOUGH)

### January 18 (Sophia)
  * Finished game, move communication between server and client.


 * Thanks for the great semester, Mr. DW!
 - Tim, Sophia, Anand
 
 

