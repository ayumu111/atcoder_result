#include <stdbool.h>
#include <stdio.h>
#define SIZE 8

typedef struct {
    char cells[SIZE][SIZE];
} Board;

typedef struct {
    char color;
    int score;
} Player;

// ボードの初期化
void initializeBoard(Board *board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board->cells[i][j] = ' ';
        }
    }
    board->cells[3][3] = 'W';
    board->cells[3][4] = 'B';
    board->cells[4][3] = 'B';
    board->cells[4][4] = 'W';
}

// プレイヤーの初期化
void initializePlayer(Player *player, char color) {
    player->color = color;
    player->score = 2;
}

// ボードの表示
void displayBoard(Board *board) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board->cells[i][j]);
        }
        printf("\n");
    }
}

// 有効な手の判定
bool isValidMove(Board *board, int row, int col, char playerColor) {
    if (board->cells[row][col] != ' ') {
        return false;
    }
    // 各方向に対して有効な手かどうかを判定するロジックを実装
    return true; // 仮の実装
}

// 指定した方向に石を反転できるか判定し、可能なら反転
bool canFlipInDirection(Board *board, int row, int col, int deltaRow,
                        int deltaCol, char playerColor) {
    int r = row + deltaRow;
    int c = col + deltaCol;
    char opponentColor = (playerColor == 'B') ? 'W' : 'B';
    bool hasOpponentStone = false;

    while (r >= 0 && r < SIZE && c >= 0 && c < SIZE &&
           board->cells[r][c] == opponentColor) {
        r += deltaRow;
        c += deltaCol;
        hasOpponentStone = true;
    }

    // 自分の色の石で挟める場合のみ反転を実行
    if (hasOpponentStone && r >= 0 && r < SIZE && c >= 0 && c < SIZE &&
        board->cells[r][c] == playerColor) {
        return true;
    }
    return false;
}

// 指定した方向に石を反転させる
void flipStonesInDirection(Board *board, int row, int col, int deltaRow,
                           int deltaCol, char playerColor) {
    int r = row + deltaRow;
    int c = col + deltaCol;
    char opponentColor = (playerColor == 'B') ? 'W' : 'B';

    while (r >= 0 && r < SIZE && c >= 0 && c < SIZE &&
           board->cells[r][c] == opponentColor) {
        board->cells[r][c] = playerColor;
        r += deltaRow;
        c += deltaCol;
    }
}

// スコアの更新
void updateScore(Board *board, Player *player) {
    int score = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board->cells[i][j] == player->color) {
                score++;
            }
        }
    }
    player->score = score;
}


// 石の配置と反転
void placeStone(Board *board, int row, int col, Player *player) {
    board->cells[row][col] = player->color;

    // 8方向に対して反転処理を実行
    int directions[8][2] = {
        {-1, 0 },
        {1,  0 }, // 上下
        {0,  -1},
        {0,  1 }, // 左右
        {-1, -1},
        {-1, 1 }, // 左上, 右上
        {1,  -1},
        {1,  1 }  // 左下, 右下
    };

    for (int i = 0; i < 8; i++) {
        if (canFlipInDirection(board, row, col, directions[i][0],
                               directions[i][1], player->color)) {
            flipStonesInDirection(board, row, col, directions[i][0],
                                  directions[i][1], player->color);
        }
    }

    updateScore(board, player);
}


// プレイヤーの手を取得
void getPlayerMove(Board *board, int *row, int *col, char playerColor) {
    do {
        printf("石を置く位置を入力してください (行 列): ");
        scanf("%d %d", row, col);
        if (!isValidMove(board, *row, *col, playerColor)) {
            printf("無効な入力です。もう一度入力してください。\n");
        }
    } while (!isValidMove(board, *row, *col, playerColor));
}

// ゲーム終了判定
bool isGameOver(Board *board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board->cells[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// メイン関数
int main() {
    Board board;
    Player player1, player2;
    initializeBoard(&board);
    initializePlayer(&player1, 'B');
    initializePlayer(&player2, 'W');
    char currentPlayerColor = player1.color;

    while (!isGameOver(&board)) {
        displayBoard(&board);
        int row, col;
        getPlayerMove(&board, &row, &col, currentPlayerColor);
        placeStone(&board, row, col,
                   (currentPlayerColor == 'B') ? &player1 : &player2);
        currentPlayerColor = (currentPlayerColor == 'B') ? 'W' : 'B';
    }

    printf("ゲーム終了！\n");
    printf("プレイヤー1 (B) のスコア: %d\n", player1.score);
    printf("プレイヤー2 (W) のスコア: %d\n", player2.score);

    return 0;
}