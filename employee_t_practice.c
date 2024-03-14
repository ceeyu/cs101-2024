// 基本Structure操作

# include <stdio.h>
# include <string.h>

typedef struct employee {
    int id;
    char name[10];
    float salary;

} employee_t;

typedef struct school {
    int sch_id; //4
    int sch_num_stu; //4
    int sch_num_tea; //4
    char sch_name[64]; //64
    char sch_address[128]; //128
    int sch_post; //4
    int sch_num_colleges; //4

    char sch_c;
} school_t;

int main(){
    employee_t my_emp;
    printf("Employee_t: %d\n", (int)sizeof(employee_t));
    printf("School_t: %d\n", (int)sizeof(school_t));

    return 0;
}
