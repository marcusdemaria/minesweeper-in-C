#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// size of game board (10x10) and number of bombs (15)
#define SIZE 10
#define BOMBS 15

//arrays to represent game board cells and tracking revealed ones
char board[SIZE][SIZE];
int revealed[SIZE][SIZE];

// initialize the game board
void initializeBoard() { // initialize board with empty cells marked as unrevealed
    for (int i = 0; i < SIZE; i++) { //loop through each row
        for (int j = 0; j < SIZE; j++) { //same with column
            board[i][j] = '-'; //each unrevealed empty cell set to this
            revealed[i][j] = 0; //mark each cell with 0 to specifiy unrevealed
        }
    }
}

// for printing the game board
void printBoard() { 
    printf("   "); //for formatting the horizontal numbers at the top of board
   
    for (int i = 0; i < SIZE; i++) { //print column numbers
        printf("%d ", i);
    }
    printf("\n"); //move to new line for board

    for (int i = 0; i < SIZE; i++) { //print row numbers
        printf("%d  ", i);
        for (int j = 0; j < SIZE; j++) { //looping through each column in row to access all cells
            if (revealed[i][j]) {
                printf("%c ", board[i][j]); //print content of revealed cells
            } else {
                printf("- "); //unrevealed cells printed as this
            }
        }
        printf("\n"); //move to next row
    }
}

// random bombs
void placeBombs() {
    srand(time(NULL)); //generating random numbers based on current time, found online and through chat gpt
    for (int i = 0; i < BOMBS; i++) { 
        int row, col;
        do { //continue to slect random row and column until an empty cell is found
            row = rand() % SIZE;
            col = rand() % SIZE;
        } while (board[row][col] == 'X'); //to make sure there isn't a bomb already in the cell
        board[row][col] = 'X';//print bomb
    }
}

// count adjacent bombs
int countAdjacentBombs(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) { //loop through the 8 cells surrounding given cell
        for (int j = -1; j <= 1; j++) {
            int newX = x + i;
            int newY = y + j;
            //checks if adjacent cell contains a bomb and is within board space
            if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && board[newX][newY] == 'X') {
                count++; //increments for each adjacent bomb found
            }
        }
    }
    return count; //returns total number of adjacent bombs
}

int main() { //this main function had help being written from chat gpt
    initializeBoard();
    placeBombs();
    int remainingCells = SIZE * SIZE - BOMBS;
    int gameOver = 0;

    printf("Welcome to Minesweeper!\n");
    printBoard();

    while (remainingCells > 0 && !gameOver) {
        int x, y;
        char input[8]; // Allow for input of "00" to "99" (2 digits)
        printf("Enter coordinates (x y): ");
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%d %d", &x, &y) != 2 || x < 0 || x >= SIZE || y < 0 || y >= SIZE || revealed[x][y]) { //checks for boundary conditions such as less or more than 2 values and non integer values
            printf("Invalid input. Try again.\n");
            continue;
        }

        if (board[x][y] == 'X') {
            gameOver = 1; //makes game over true and executes it
        } else{
            int adjacentBombs = countAdjacentBombs(x, y);
            board[x][y] = (char)(adjacentBombs + '0');
            revealed[x][y] = 1; //adds another revealed tile
            remainingCells--; //removes a remaining tile from list

            if (remainingCells == 0) {
                printf("Congratulations! You won!\n");
                printBoard();
            } else if (!gameOver) {
                printBoard();
            }
        }
    }

    if (gameOver) {
        printf("Game Over! You hit a bomb.\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 'X') {
                    revealed[i][j] = 1;
                }
            }
        }
        printBoard();
    }

    return 0;
}


