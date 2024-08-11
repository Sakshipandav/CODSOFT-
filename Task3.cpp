#include <iostream>

using namespace std;

char board[3][3];  // The 3x3 grid

// Function to initialize the game board
void initializeBoard() {
    int k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + k;  // Assign numbers 1-9 to the board
            k++;
        }
    }
}

// Function to display the current state of the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to prompt the current player to enter their move
void playerMove(char player) {
    int move;
    while (true) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        if (move >= 1 && move <= 9) {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = player;
                break;
            } else {
                cout << "Invalid move! The spot is already taken.\n";
            }
        } else {
            cout << "Invalid move! Please enter a number between 1 and 9.\n";
        }
    }
}

int main() {
    char currentPlayer = 'X';
    bool gameOngoing = true;

    do {
        initializeBoard();
        displayBoard();

        while (true) {
            playerMove(currentPlayer);
            displayBoard();

            if (checkWin(currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            } else if (checkDraw()) {
                cout << "The game is a draw!\n";
                break;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // Ask if the players want to play again
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'n' || playAgain == 'N') {
            gameOngoing = false;
        }
    } while (gameOngoing);

    cout << "Thanks for playing!\n";
    return 0;
}
