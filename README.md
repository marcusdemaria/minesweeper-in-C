# minesweeper-in-C
Implementing minesweeper into C. Basic yet fun, and who doesn't love minesweeper? MECHTRON2MP3 Fall 2023 A1.

# Project Overview

In this assignment, you are tasked with implementing the classic game of Minesweeper in C. Minesweeper is a classic computer game that comes pre-installed on many Windows operating systems. The objective of the game is to clear a grid of cells without detonating hidden mines. Players click on cells to reveal numbers, which indicate how many mines are adjacent to that cell. By using logic and deduction, players must flag cells they suspect contain mines and uncover safe cells until they’ve cleared the entire grid or flagged all the mines. Minesweeper is a popular puzzle game that challenges players to think strategically and logically while avoiding mines. It’s a great example of a simple yet engaging game that can be implemented as a programming project, especially for learning purposes. Students can create their own textbased version of Minesweeper in C, which would involve working with 2D arrays, loops, and conditional statements to manage the game grid and implement game rules.

# Functionality

Write all your codes in a single file named main.c . In this assignment you need to
implement a simplified version of the Minesweeper game in C using a 10x10 array. Declare
a 2D array variable with char board[SIZE][SIZE] , where #define SIZE 10 is defined at
the top of you code. You can initialize all the element of board array with ’-’ . The code
must generate hidden bombs randomly, using srand() function. You can define a function
called void placeBombs(char board[SIZE][SIZE]) , to receive the board array an place
15 bombs ( #define BOMBS 15 ) randomly in this array and replacing ’-’ s with ’X’ s. <br>

Then, the game must allow the player to input coordinates to reveal cells one by
one. In this part the code must be able to handle potential unacceptable inputs. The board
array is a 10by10 matrix. It means the location of element must be an index between 0 to
9 (indexing in C starts with zero!). If the input is out of this range it must print a proper
message and continue to the next iteration. The other error might be when the input is
the location of an element that it is already revealed! Then, if board[i][j] == ’X’ , where
i and j are index inputs given by user, it means you hit a bomb and the game is over!
If not, in every iteration, the code must reveal the number of bombs adjacent to a revealed
cell. Every element with (i,j) index in array board is surrounded by 8 elements.
If the user chose (i,j) and it is not a bomb, then if there is/are n bomb(s) in the above
mention elements, it should print the number n in terminal. <br>

If the user chose (i,j) and it is not a bomb, then if there is/are n bomb(s) in the above
mention elements, it should print the number n in terminal.
