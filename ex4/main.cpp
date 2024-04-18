
#include <iostream>

class Car{
    protected:
    string m_DriveMode;
    private:
    int m_MaxSteating;
    int m_price;
    void m_UpdatePrice(int base = 500000){
        
    }
    public: 
    string m_board;
    string m_model;
    int m_year;
    
    Car(string x, string y, int z,int s){
        
    }
    
    int get_MaxSeating(){}
    int get_Price{}
    string get_DriveMode(){}
}

class BMW_Car: public Car{
    public:
    BMW_Car(string y, int z, int s){
        cout << "Constructing BMW_Car\n";
        m_DriveMode = "Real-wheel";
    }
    
    string get_DriveMode(){
        
    }
}

class AUDI_Car: public Car{
    public:
    AUDI_Car(string y,int z,int s): Car("Audi",y,z,s){
        cout << "Constructing AUDI_Caru_Car\n";
        m_DriveMode = "Front-wheel";
    }
    
    string get_DriveMode(){
        
    }
}

int main()
{
   

    return 0;
}
