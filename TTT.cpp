#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(char board[][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the game is over
bool isGameOver(char board[][3]) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
    }
    // Check columns
    for(int j=0; j<3; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return true;
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;
    return false;
}

// Function to get the move from the user
void getUserMove(char board[][3]) {
    int row, col;
    cout << "Enter your move (row column): ";
    cin >> row >> col;
    while(row<1 || row>3 || col<1 || col>3 || board[row-1][col-1] != ' ') {
        cout << "Invalid move. Enter your move (row column): ";
        cin >> row >> col;
    }
    board[row-1][col-1] = 'X';
}

// Function to get the move from the AI bot
void getAIMove(char board[][3]) {
    // Generate a random move
    srand(time(NULL));
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while(board[row][col] != ' ');
    board[row][col] = 'O';
}

// Main function to play the game
int main() {
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int turn = 1;
    while(!isGameOver(board)) {
        cout << "Turn " << turn << endl;
        printBoard(board);
        if(turn % 2 == 1) {
            getUserMove(board);
        } else {
            getAIMove(board);
        }
        turn++;
    }
    printBoard(board);
    if(turn % 2 == 0) {
        cout << "You win!" << endl;
    } else {
        cout << "AI wins!" << endl;
    }
    return 0;
}
