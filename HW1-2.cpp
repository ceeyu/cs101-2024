#include <stdio.h>

int main() {
    char ch;
    int count;

    // 持續讀取字符-次數對，直到無有效輸入
    while (scanf("%c%d", &ch, &count) == 2) {
        // 輸出：根據次數重複字符
        for (int i = 0; i < count; i++) {
            printf("%c", ch);
        }
    }
    printf("\n");

    return 0;
}
