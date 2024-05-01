#include <iostream>

using namespace std;

const int BOARD_SIZE = 3; // 定義棋盤大小（3x3）

class TicTacToe {
private:
    char board[BOARD_SIZE][BOARD_SIZE]; // 宣告二維陣列來存儲棋盤
    int currentPlayer; // 當前玩家

    void initializeBoard() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = '1' + i * BOARD_SIZE + j; // 初始化所有單元格
            }
        }
    }

    void displayPlayerInfo() {
        cout << "Player 1 (X) - Player 2 (O)" << endl;
    }

    void displayBoard() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                cout << " " << board[i][j];
                if (j < BOARD_SIZE - 1)
                    cout << " |";
            }
            cout << endl;
            if (i < BOARD_SIZE - 1)
                cout << "---+---+---" << endl;
        }
        cout << endl;
        cout << "==> Player " << (currentPlayer == 1 ? 1 : 2) << " (" << (currentPlayer == 1 ? 'X' : 'O') << "), enter a number: ";
    }

    bool makeMove(int move) {
        if (move < 1 || move > BOARD_SIZE * BOARD_SIZE) {
            return false; // 無效的移動（超出範圍）
        }

        int row = (move - 1) / BOARD_SIZE;
        int col = (move - 1) % BOARD_SIZE;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            return false; // 單元格已被佔用
        }

        if (currentPlayer == 1) {
            board[row][col] = 'X';
        } else {
            board[row][col] = 'O';
        }

        return true; // 有效的移動
    }

    bool checkWin() {
        // 檢查行、列和對角線是否有相同符號
        for (int i = 0; i < BOARD_SIZE; i++) {
            // 檢查行
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true; // 玩家贏得一行
            }
            // 檢查列
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true; // 玩家贏得一列
            }
        }
        // 檢查對角線
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
            return true; // 玩家贏得對角線
        }

        return false; // 尚未贏得
    }

    bool isTie() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    return false; // 找到空單元格，遊戲尚未平局
                }
            }
        }
        return true; // 所有單元格都被填滿，遊戲平局
    }

public:
    TicTacToe() {
        currentPlayer = 1; // 從玩家1開始
        initializeBoard();
        cout << "-- Tic Tac Toe -- CSIE@CGU" << endl;
        displayPlayerInfo();
    }

    void run() {
        bool gameWon = false;
        bool gameTied = false;

        while (!gameWon && !gameTied) {
            displayBoard();

            int move;
            cin >> move;

            while (!makeMove(move)) {
                cout << "==> Invalid value, please enter again: ";
                cin >> move;
            }

            if (checkWin()) {
                gameWon = true;
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else if (isTie()) {
                gameTied = true;
                cout << "==> Game draw" << endl;
            }

            // 切換到另一個玩家
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }
};

int main() {
    TicTacToe game;
    game.run();
    return 0;
}
