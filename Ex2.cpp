# include <stdio.h>

int main() {
    FILE* fp;

    // 三個陣列
    int a[] = {0, 1, 2};
    char b[] = {'a', 'b', 'c'};
    float c[] = {1.1, 1.2, 1.3};

    // 開啟檔案以二進位形式寫入
    fp = fopen("a.bin", "wb");

    // 檢查檔案是否成功開啟
    if (fp == NULL) {
        perror("檔案開啟失敗");
        return 1;
    }

    // 寫入三個陣列
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);

    // 關閉檔案
    fclose(fp);

    // 再次開啟檔案以二進位形式讀取
    fp = fopen("a.bin", "rb");

    // 檢查檔案是否成功開啟
    if (fp == NULL) {
        perror("檔案開啟失敗");
        return 1;
    }

    // 讀取三個陣列
    int readA[3];
    char readB[3];
    float readC[3];

    fread(readA, sizeof(int), 3, fp);
    fread(readB, sizeof(char), 3, fp);
    fread(readC, sizeof(float), 3, fp);

    // 關閉檔案
    fclose(fp);

    // 輸出讀取到的陣列內容
    printf("Array A: %d, %d, %d\n", readA[0], readA[1], readA[2]);
    printf("Array B: %c, %c, %c\n", readB[0], readB[1], readB[2]);
    printf("Array C: %.2f, %.2f, %.2f\n", readC[0], readC[1], readC[2]);

    return 0;
}
