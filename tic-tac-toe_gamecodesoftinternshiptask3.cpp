#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';

void printBoard() {
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

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void getPlayerInput() {
    int move;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;
        move--;
        int row = move / 3, col = move % 3;
        if (move >= 0 && move < 9 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            break;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

void playGame() {
    while (true) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';
        currentPlayer = 'X';
        
        while (true) {
            printBoard();
            getPlayerInput();
            
            if (checkWin()) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (isDraw()) {
                printBoard();
                cout << "It's a draw!\n";
                break;
            }
            switchPlayer();
        }
        
        cout << "Do you want to play again? (y/n): ";
        char playAgain;
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') break;
    }
}

int main() {
    playGame();
    return 0;
}
