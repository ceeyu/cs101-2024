#include <stdio.h>
#include <string.h>

int main() {
    // 讀取
    FILE *inputFile = fopen("main3.c", "r");

    // 寫入
    FILE *outputFile = fopen("main3.txt", "w");

    // 檢查
    if (inputFile == NULL) {
        //fprintf(stderr, "失敗 main3.c\n");
        return 1;
    }

    if (outputFile == NULL) {
        //fprintf(stderr, "失敗 main3.txt\n");
        return 1;
    }

    // 找到main
    char line[1000];
    int lineCount = 0;
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        lineCount++;
        if (strstr(line, "int main()") != NULL) {
            // 找到包含 "int main()" 的行，寫入 main3.txt 文件
            fprintf(outputFile, "%d", lineCount);
            break; // 找到一次就退出
        }
    }

    // 如果沒有找到 "int main()"，則輸出 0
    if (!feof(inputFile) && ferror(inputFile)) {
        fprintf(outputFile, "0");
    }

    // 關閉文件
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
