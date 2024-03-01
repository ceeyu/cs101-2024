 #include <stdio.h>

void print_sp(int i, int n){
    for (int sp = 0; sp < n-i; sp++){
        printf(" ");
    }
}

void print_num(int n){
    for (int i = 0; i < 2*n-1;i++){
        printf("%d", n);
    }
    printf("\n");
}

int main(){
    int rows = 6;
    for (int i = 0; i <= rows; i++){
        print_sp(i, rows);
        print_num(i);
    }
    return 0;
}