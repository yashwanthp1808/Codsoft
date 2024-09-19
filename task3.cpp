#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "Tic-Tac-Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

int checkWin() {
    // Rows, Columns, Diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;

    return 0; // No winner
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

void game() {
    int playerWon = 0;
    int slot;
    currentPlayer = 1;
    currentMarker = 'X';
    
    drawBoard();
    
    for (int i = 0; i < 9; i++) {
        cout << "Player " << currentPlayer << "'s turn. Enter your move (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid move! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try again.\n";
            i--;
            continue;
        }

        drawBoard();
        playerWon = checkWin();
        
        if (playerWon) {
            cout << "Player " << playerWon << " wins!\n";
            break;
        }

        switchPlayer();
    }

    if (!playerWon) {
        cout << "It's a draw!\n";
    }
}

int main() {
    char playAgain;

    do {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '1' + (3 * i + j); // Reset the board
            }
        }
        game();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y');

    return 0;
}
