#include <stdio.h>
#include <string.h>
#include <ctype.h>

void runLengthDecoding(char *input, char *output) {
    int len = strlen(input);
    int count = 0;
    char currentChar;

    for (int i = 0; i < len; ++i) {
        // 檢查字符是否為數字
        if (isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
        } else {
            // 將字符重複 count 次附加到輸出字符串
            for (int j = 0; j < count; ++j) {
                sprintf(output, "%s%c", output, input[i]);
            }
            // 重置計數
            count = 0;
        }
    }
}

int main() {
    char input[100];  // 用來接收使用者輸入的字串
    char output[100] = "";  // 預設大小為100，你可以根據實際需要調整

    // 提示用戶輸入字串
    printf("請輸入要進行 Run-Length Decoding 的字串: ");
    scanf("%s", input);

    runLengthDecoding(input, output);

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);

    return 0;
}
