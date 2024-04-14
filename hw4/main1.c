#include <stdio.h>

typedef struct {
    int* calloced_p[10]; // 用來記錄分配的記憶體指標
} my_mm_t;

int g_mm[10]; // 全域變數記憶體空間

my_mm_t mms; // 全域變數管理記憶體

void print_calloc_array(int flag) {
    for (int i = 0; i < 10; i++) {
        (mms.calloced_p[i]) ? printf("1") : printf("0"); // 印出已分配的記憶體位置
    }
    if (!flag) {
        printf(" <- Out of space"); // 如果超出範圍，顯示 "Out of space"
    }
    printf("\n");
}

int* my_calloc(int n, int size) {
    int av_size = 0; // 可用大小
    int index;
    for (index = 0; index < 10; index++) {
        if (!mms.calloced_p[index]) {
            av_size++;
        } else {
            av_size = 0;
        }

        if (av_size == size) { // 找到連續空間大於等於要求的大小
            index -= size - 1; // 更新 index
            break;
        }
    }
    if (av_size < size) { // 如果可用空間小於要求大小，則印出 "Out of space"
        print_calloc_array(0);
        return NULL;
    }
    for (int i = 0; i < size; i++) { // 將找到的連續空間標記為已分配
        mms.calloced_p[index + i] = &g_mm[index];
    }
    print_calloc_array(1); // 印出 mms 的值
    return &g_mm[index];
}

void my_free(int* p) {
    for (int i = 0; i < 10; i++) {
        if (mms.calloced_p[i] == p) {
            mms.calloced_p[i] = NULL; // 將釋放的記憶體指標標記為空
        }
    }
    print_calloc_array(1); // 印出 mms 的值
}

int main() {
    int* np1 = my_calloc(1, 1);
    int* np2 = my_calloc(1, 2);
    int* np3 = my_calloc(1, 3);
    int* np4 = my_calloc(1, 4);
    my_free(np1);
    my_free(np4);
    int* np5 = my_calloc(1, 5);
    int* np6 = my_calloc(1, 1);
    return 0;
}
