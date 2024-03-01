#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        // 交換字元
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char input[100];  // 假設輸入的單詞不超過100個字元

    // 提示用戶輸入單詞
    printf("請輸入一個單詞: ");
    scanf("%s", input);

    // 反向單詞
    reverseString(input);

    // 顯示反向後的單詞
    printf("反向後的單詞: %s\n", input);

    return 0;
}
