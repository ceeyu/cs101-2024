#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lotto_record_t {
    int lotto_num;
    float lotto_receipt;
    int emp_id;
    char lotto_date[16];
    char lotto_time[16];
} lotto_record_t;

int rand_num_mod70() {
    return rand() % 69+1;
}

// int rand_num_mod11() {
//     return rand() % 11;
// }

void get_rad_num(int lotto_array[7]) {
    for (int j = 0; j < 7; j++) {
        //if (j < 6) {
            lotto_array[j] = rand_num_mod70();
        //}
        // else {
        //     lotto_array[6] = rand_num_mod11();
        // }
        // Check that lotto_array[j] isn't 0
        if (lotto_array[j] == 0) {
            lotto_array[j] = rand_num_mod70();
        }
    }
}

void array_swap(int lotto_array[7]) {
    int tmp = 0;
    for (int j = 0; j < 6; j++) {
        for (int arr_lotto = j; arr_lotto < 6; arr_lotto++) {
            if (lotto_array[j] > lotto_array[arr_lotto]) {
                tmp = lotto_array[j];
                lotto_array[j] = lotto_array[arr_lotto];
                lotto_array[arr_lotto] = tmp;
            }
        }
    }
}

void array_rerandom(int lotto_array[7]) {
    for (int j = 0; j < 6; j++) {
        for (int z = 0; z < 6; z++) {
            while ((lotto_array[j] == lotto_array[z] && j != z) || lotto_array[j] == lotto_array[6]) {
                lotto_array[j] = rand_num_mod70();
            }
        }
    }
}

void print_array(int lotto_array[7], FILE* fp) {
    for (int j = 0; j < 7; j++) {
        fprintf(fp, "%.2d ", lotto_array[j]);
    }
    fprintf(fp, "\n");
}

void print_last(int num_row, FILE* fp, int id_numx) {
    for (int i = num_row + 1; i < 6; i++) {
        fprintf(fp, "[%d]: ", i);
        for (int j = 0; j < 7; j++) {
            fprintf(fp, "__");
            if(j != 6){
                fprintf(fp," ");
            }
            else
            {
                fprintf(fp, "\n");
            }
            
        }
    }
    fprintf(fp, "========= csie@CGU =========\n");
}



int main() {
    FILE* fp;
    FILE* fr;
    int sell_num[1] = { 1 }, sell_numplus[1] = { 1 }, row_num = 0, id_numx;

    scanf("%d", &row_num);
    if ((fr = fopen("a.bin", "r")) == NULL) {
        fr = fopen("a.bin", "wb");
        fwrite(sell_num, sizeof(int), 1, fr);
    }
    else {
        fr = fopen("a.bin", "rb");
        fread(sell_num, sizeof(int), 1, fr);
        fseek(fr, 0, SEEK_SET);
        fclose(fr);
        fr = fopen("a.bin", "wb+");
        sell_numplus[0] = sell_num[0] + 1;
        fwrite(sell_numplus, sizeof(int), 1, fr);
    }
  	srand(1);
    int n = snprintf(NULL, 0, "lotto.txt");
    char s1[n + 1];
    snprintf(s1, sizeof(s1), "lotto.txt");
    fp = fopen(s1, "w+");
    fclose(fr);
    time_t curtime;
    time(&curtime);
    fprintf(fp, "========= lotto649 =========\n");
    if (row_num <= 5) {
        for (int i = 1; i <= row_num; i++) {
            int lotto_array[7] = { 0 };
            get_rad_num(lotto_array);
            fprintf(fp, "[%d]: ", i);
            array_rerandom(lotto_array);
            array_swap(lotto_array);
            print_array(lotto_array, fp);
        }
    }
    else {
        for (int i = 1; i <= 5; i++) {
            int lotto_array[7] = { 0 };
            get_rad_num(lotto_array);
            fprintf(fp, "[%d]: ", i);
            array_rerandom(lotto_array);
            array_swap(lotto_array);
            print_array(lotto_array, fp);
        }
    }
    print_last(row_num, fp, id_numx);
    fclose(fp);
    int row_num_array[1];
    row_num_array[0] = row_num;
    return 0;
}
