#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // for _getch() function
#include <stdbool.h>
#include <windows.h> // for Sleep function (Windows)

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to clear the screen
void clearScreen() {
    system("cls");
}

// Function to print the map
void printMap(char map[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

// Function to move the player
void movePlayer(char map[MAX_ROWS][MAX_COLS], int *playerRow, int *playerCol, char direction) {
    int newRow = *playerRow;
    int newCol = *playerCol;

    switch (direction) {
        case 'w':
            newRow--;
            break;
        case 'a':
            newCol--;
            break;
        case 's':
            newRow++;
            break;
        case 'd':
            newCol++;
            break;
        case 'u':
            // Implement undo logic here
            break;
        default:
            return;
    }

    // Check if the new position is within bounds and is a valid move
    if (newRow >= 0 && newRow < MAX_ROWS && newCol >= 0 && newCol < MAX_COLS &&
        (map[newRow][newCol] == ' ' || map[newRow][newCol] == '.')) {
        // Update the map and player's position
        map[*playerRow][*playerCol] = '.';
        *playerRow = newRow;
        *playerCol = newCol;
        map[*playerRow][*playerCol] = 'P';
    }
}

int main() {
    char map[MAX_ROWS][MAX_COLS];
    int rows, cols;
    int playerRow, playerCol;
    char command;

    // Read map size and map content from a text file
    FILE *file = fopen("map.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open the file.\n");
        return 1;
    }

    fscanf(file, "%d %d", &rows, &cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, " %c", &map[i][j]);
            if (map[i][j] == 'P') {
                playerRow = i;
                playerCol = j;
            }
        }
    }

    fclose(file);

    // Main game loop
    while (true) {
        clearScreen();
        printMap(map, rows, cols);
        printf("Enter a command (w/a/s/d/u) or press ESC to exit: ");
        command = _getch();

        if (command == 27) { // ESC key (ASCII code 27) to exit the game
            break;
        }

        movePlayer(map, &playerRow, &playerCol, command);

        // Implement car movement logic here

        // Implement win condition check here

        // Implement undo functionality

        // Check for game over condition

        // Delay for a moment to make the game more playable
        Sleep(100); // Uncomment this line and include windows.h for Windows
    }

    return 0;
}
