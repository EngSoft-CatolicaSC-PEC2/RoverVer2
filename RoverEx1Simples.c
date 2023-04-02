#include <stdio.h>
#include <string.h>

#define MATRIX_SIZE 8
#define RIGHT 'R'
#define LEFT 'L'
#define UP 'U'
#define DOWN 'D'
#define DESTINATION 'D'
#define TRAIL 'T'
#define BLOCKED 'B'
#define TERRAIN '*'

int roverRow = 2;
int roverColumn = 2;
int destinationRow = 2;
int destinationColumn = 4;
char matrix[MATRIX_SIZE][MATRIX_SIZE];

// Loads the initial terrain matrix with the 'TERRAIN' character
void loadMatrix();

// Prints the current state of the matrix
void printMatrix();

// Initializes the terrain matrix with the rover and destination positions
void initMatrix();

// Moves the rover in the direction specified by the command character ('R', 'L', 'U', 'D')
void moveRover(char);

// Adds a trail marker to the current rover position
void leaveTrail();

// Returns 1 if the rover is at the edge of the matrix, 0 otherwise
int isEdge();

// Returns 1 if the rover is at the right edge of the matrix, 0 otherwise
int isRightEdge();

// Returns 1 if the rover is at the left edge of the matrix, 0 otherwise
int isLeftEdge();

// Returns 1 if the rover is at the top edge of the matrix, 0 otherwise
int isTopEdge();

// Returns 1 if the rover is at the bottom edge of the matrix, 0 otherwise
int isBottomEdge();

// Returns 1 if the rover has reached its destination, 0 otherwise
int reachedDestination();

int main() {
    loadMatrix();
    initMatrix();
    printMatrix();

    do {
        moveRover(RIGHT);
        printMatrix();
    } while (reachedDestination() == 0);
}

void moveRover(char command) {
    if (command == RIGHT && isRightEdge() != 0) {
        roverColumn++;
        leaveTrail();
    } else if (command == LEFT && isLeftEdge() != 0) {
        roverColumn++;
        leaveTrail();
    }
}

int reachedDestination() {
    return roverColumn == destinationColumn && roverRow == destinationRow;
}

int isEdge(){
    return isRightEdge() && isLeftEdge() && isBottomEdge() && isTopEdge();
}

int isRightEdge() {
    return roverColumn < MATRIX_SIZE;
}

int isLeftEdge() {
    return roverColumn > 0;
}

int isTopEdge() {
    return roverRow > 0;
}

int isBottomEdge() {
    return roverRow < MATRIX_SIZE;
}

void leaveTrail() {
    matrix[roverRow][roverColumn] = TRAIL;
}

void initMatrix() {
    matrix[roverRow][roverColumn] = TRAIL;
    matrix[destinationRow][destinationColumn] = DESTINATION;
}

void loadMatrix() {
    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int column = 0; column < MATRIX_SIZE; column++) {
            matrix[row][column] = TERRAIN;
        }
    }
}

void printMatrix() {

    printf("\n < PRINT >\n");
    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int column = 0; column < MATRIX_SIZE; column++) {
            printf("%c ", matrix[row][column]);
        }
        printf("\n");
    }
    printf(" <->\n");
}
