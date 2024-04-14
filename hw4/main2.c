#include <stdio.h>

// 定義 multiplication 函式，用於生成九九乘法表
void multiplication(int i, int j) {
    // 確保 i 和 j 都在合理範圍內
    if (i > 9 || j > 9) {
        return; // 超出範圍則返回
    }
    // 印出乘法表的每一個等式，並以空白符號間隔
    printf("%d*%d=%d", i, j, i * j);
    // 如果 j 等於 9，表示已經列印完一行，需要換行
    if (j == 9) {
        printf("\n"); // 換行
        multiplication(i + 1, 1); // 調用 multiplication 函式，開始新的一行
    } else {
        printf(" "); // 空白符號間隔
        multiplication(i, j + 1); // 繼續列印同一行的下一個等式
    }
}

// 主函式
int main() {
    multiplication(1, 1); // 從 1*1 開始列印九九乘法表
    return 0;
}
