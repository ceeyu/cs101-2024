#include <stdio.h>

int main() {
    // 打开 main2.c 文件进行讀取
    FILE *inputFile = fopen("main2.c", "r");

    // 寫入
    FILE *outputFile = fopen("main2.txt", "w");

    // 成功開啟
    if (inputFile == NULL) {
        // fprintf(stderr, "失敗 main2.c\n");
        return 1;
    }

    if (outputFile == NULL) {
        // fprintf(stderr, "失敗 main2.txt\n");
        return 1;
    }

    // 寫入
    char line[1000];
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        fputs(line, outputFile);
    }

    // 關閉
    fclose(inputFile);
    fclose(outputFile);

    //printf("完成 main2.txt\n");

    return 0;
}
