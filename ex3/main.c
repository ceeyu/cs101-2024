# include <stdio.h>
# include <string.h>

typedef struct employee {
    int id;
    char name[10];
    int age;
    float salary;

} employee_t;




void emp_info(employee_t emp){ //傳一個元素
    pritnf("emplyee id = %d\n", emp.id);
    pritnf("emplyee name = %s\n", emp.name);
    pritnf("emplyee age = %d\n", emp.age);
    pritnf("emplyee salary = %02f\n\n", emp.salary);
}

int emp_average_age(employee_t emp[],int n){ //傳一個陣列
    int sum = 0;
    for(int i=0;i<3;i++){
        sum += emp[i].age;
    }
    return sum/3;
}

void emp_writefile(employee_t emp[],int n){ //讀寫(寫)檔案函式
    FILE* fp = fopen("employee.bin","wb+");
    for(int i=0;i<n;i++){
        // fwrite(&emp[i], sizeof(employee_t),1,fp);
        fwrite(emp+i,sizeof(employee_t),1,fp); //指標寫法
    }
    fclose(fp);
    return;
}

void emp_readfile(employee_t emp[],int n){ //讀寫(讀)檔案函式
    FILE* fp = fopen("employee.bin","rb");
    int i=0;
    employee_t tmp;
    //while(fread(&emp[i],sizeof(employee_t),1,fp)){
    while(fread(&tmp,sizeof(employee_t),1,fp)){ //指標寫法
        emp[i].id = tmp.id;
        emp[i].age = tmp.age;
        emp[i].salary=tmp.salary;
        strcpy(emp[i].name,tmp.name);
        printf("[%d] %d %s\n",i,emp[i].id,emp[i].name);
        i++;
    }
    fclose(fp);
    return;
}

int main(){
    employee_t emp[3];
    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0;
    strcpy(emp[0].name,"IU");

    emp[1].id = 2;
    emp[1].age = 26;
    emp[1].salary = 36000.0;
    strcpy(emp[0].name,"taylor");

    emp[2].id = 3;
    emp[2].age = 31;
    emp[2].salary = 90000.0;
    strcpy(emp[0].name,"swift");

    int age = emp_average_age(emp, 3);
    printf("Average age: %d\n\n", age);

    emp_writefile(emp,3);
    employee_t read_emp[10];
    emp_readfile(read_emp,3);

    for(int i=0;i<3;i++){
        emp_info(emp[i]);
    }

    return 0;
}
