#include <stdio.h>
#include <stdlib.h>

// 函數將8位二進制轉換為16進制
char binaryToHex(char *binary) {
    int decimal = strtol(binary, NULL, 2); // 將二進制字符串轉換為十進制
    char hex[3];
    sprintf(hex, "%X", decimal); // 將十進制轉換為16進制字符串
    return hex[0];
}

int main() {
    char binary[9]; // 8位的二進制字符串，加上結尾的'\0'
    printf("請輸入8位的二進制字符串: ");
    scanf("%8s", binary);

    if (strlen(binary) != 8) {
        printf("請輸入正確的8位二進制字符串。\n");
        return 1;
    }

    char hex = binaryToHex(binary);
    printf("16進制表示: %c\n", hex);

    return 0;
}
