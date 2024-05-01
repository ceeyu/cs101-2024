#include <iostream>

using namespace std;

const int BOARD_SIZE = 3; // Define the board size (3x3)

char board[BOARD_SIZE][BOARD_SIZE]; // Declare 2D array to store game board

void initializeBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '-'; // Initialize all cells with '-' (empty)
    }
  }
}

void displayBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

bool makeMove(int player, int row, int col) {
  if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
    return false; // Invalid move (out of bounds)
  }

  if (board[row][col] != '-') {
    return false; // Cell already occupied
  }

  if (player == 1) {
    board[row][col] = 'X';
  } else {
    board[row][col] = 'O';
  }

  return true; // Valid move
}

bool checkWin(int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
      return true; // Player has a winning row
    }
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
      return true; // Player has a winning column
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
    return true; // Player has a winning diagonal (top-left to bottom-right)
  }

  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
    return true; // Player has a winning diagonal (top-right to bottom-left)
  }

  return false; // No winning condition yet
}

bool isTie() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == '-') {
        return false; // Empty cell found, so not a tie
      }
    }
  }

  return true; // All cells filled, so it's a tie
}

int main() {
  int player = 1; // Start with player 1
  bool gameWon = false;
  bool gameTied = false;

  initializeBoard();

  while (!gameWon && !gameTied) {
    displayBoard();

    cout << "Player " << player << ", enter your move (row, col): ";
    int row, col;
    cin >> row >> col;

    while (!makeMove(player, row, col)) {
      cout << "Invalid move. Try again: ";
      cin >> row >> col;
    }

    if (checkWin(player)) {
      gameWon = true;
      cout << "Player " << player << " wins!" << endl;
    } else if (isTie()) {
      gameTied = true;
      cout << "It's a tie!" << endl;
    }

    // Switch to the other player
    player = (player == 1) ? 2 : 1;
  }

  displayBoard();

  return 0;
}
