#include <stdio.h>
#include <string.h>

void runLengthEncoding(char *input, char *output) {
    int len = strlen(input);
    int count = 1;

    for (int i = 0; i < len; ++i) {
        // 檢查下一個字符是否相同
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // 將字符和計數附加到輸出字符串
        sprintf(output, "%s%c%d", output, input[i], count);

        // 重置計數
        count = 1;
    }
}

int main() {
    char input[100];  // 用來接收使用者輸入的字串
    char output[100] = "";  // 預設大小為100，你可以根據實際需要調整

    // 提示用戶輸入字串
    printf("請輸入要進行 Run-Length Encoding 的字串: ");
    scanf("%s", input);

    runLengthEncoding(input, output);

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);
    printf("\n");

    return 0;
}
