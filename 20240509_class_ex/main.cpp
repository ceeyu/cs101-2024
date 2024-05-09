/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void foo_ref(int& b){
        b = 10;
}
    
void foo_pointer(int* b){
        *b = 20;
}
    
void foo(int b){
        b = 30;
}

void swap_pointer(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

class MyString{
    private:
    string m_str;
    public:
    MyString(string str){
        m_str = str;
    }
    string& get_str(){
        cout << "&m_str " << &m_str <<endl;
        return m_str;
    }
    string get_mystr(){
        cout << "&m_str " << &m_str <<endl;
        return m_str;
    }
    
};

int main()
{
    string str = "CSIE";
    string& ref = str;

    cout << "ref= " << ref << endl;
    cout << "str= " << str << endl;
    
    int a = 0;
    cout << a << endl;
    foo_ref(a);
    cout << a << endl;
    foo_pointer(&a);
    cout << a << endl;
    foo(a);
    cout << a << endl;

    
    int c = 111;
    int d = 222;
    cout << "Before swap, value of c: " << c << endl;
    cout << "Before swap, value of d: " << d << endl;

    swap_pointer(&c,&d);
    cout << "Before swap, value of c: " << c << endl;
    cout << "Before swap, value of d: " << d << endl;
    
    MyString base_str ("IU");
    string& p =base_str .get_str();
    cout << p <<endl;
    p = "CSIE";
    cout << base_str .get_mystr() << endl;
    return 0;
}
