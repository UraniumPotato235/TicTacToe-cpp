#include <bits/stdc++.h>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    system("CLS"); 
    cout << "Welcome to Tic-Tac-Toe!" << endl;

    cout << "  1  2  3" << endl; // Column labels

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " "; // Row labels
        for (int j = 0; j < 3; j++) {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
        if (i < 2) 
            cout << "  --+-+--" << endl;
    }
//     cout << "  -+-+-" << endl; // Horizontal divider
}

bool isBoardEmpty(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell != ' ')
                return false;
        }
    }
    return true;
}

// Function to check if the game is over
bool isGameOver(const vector<vector<char>>& board) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;

    // Check if the board is full (a draw)
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }

    return true;
}

void playAgain();

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    bool player1Turn = true;


    while (!isGameOver(board)) {
        printBoard(board);

        char symbol = (player1Turn) ? 'X' : 'O';
        int row, col;
        int r, c;

        cout << "Player " << (player1Turn ? "1 (X)" : "2 (O)") << ", enter your move (row and column): ";
        cin >> r >> c;
        row = r - 1;
        col = c - 1;

        // Check if the input is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = symbol;
        player1Turn = !player1Turn;
    }

    printBoard(board);
    
    // Determine the winner or declare a draw
    if (isGameOver(board) && !isBoardEmpty(board)) {
        if (player1Turn)
            cout << "Player 2 (O) wins!" << endl;
        else
            cout << "Player 1 (X) wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    playAgain();

    return 0;
}

void playAgain(){
    
    cout << "Do you want to play again? (Y/N): ";
    char choice;
    cin >> choice;

    system("CLS");

    if (choice == 'Y' || choice == 'y'){
        main();
    }
    else if (choice == 'N' || choice == 'n'){
        cout << "Thanks for playing!" << endl;
    }
    else{
        cout << "Invalid input. Try again." << endl;
        playAgain();
    }
}
