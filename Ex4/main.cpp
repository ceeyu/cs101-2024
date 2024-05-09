#include <iostream>
#include <string>

using namespace std;

class Engine {
private:
    bool m_isRunning;

public:
    Engine() {
        m_isRunning = false;
    }

    void Start() {
        if (!m_isRunning) {
            m_isRunning = true;
            cout << "Engine started" << endl;
        } else {
            cout << "Engine is already running" << endl;
        }
    }

    void Stop() {
        if (m_isRunning) {
            m_isRunning = false;
            cout << "Engine stopped" << endl;
        } else {
            cout << "Engine is already stopped" << endl;
        }
    }

    bool IsRunning() const {
        return m_isRunning;
    }
};

class Fueltank {
private:
    int m_fuelLevel;
    int m_gasGrade;

public:
    Fueltank() {
        m_fuelLevel = 0;
        m_gasGrade = 92;
    }

    int GetFuelLevel() const {
        return m_fuelLevel;
    }

    int GetGasGrade() const {
        return m_gasGrade;
    }

    void SetGasGrade(int gasGrade) {
        if (gasGrade >= 92 && gasGrade <= 98) {
            m_gasGrade = gasGrade;
            cout << "Set Gas_grade: " << m_gasGrade << endl;
        } else {
            cout << "Invalid gas grade: " << gasGrade << endl;
        }
    }

    void Refuel(int amount, int gasGrade) {
        if (amount > 0 && gasGrade >= 92 && gasGrade <= 98) {
            m_fuelLevel += amount;
            cout << "fuel_up: " << amount << " Gas_grade: " << gasGrade << endl;
        } else {
            cout << "Invalid refueling request: amount = " << amount << ", gasGrade = " << gasGrade << endl;
        }
    }
};

class AUDI_Car {
private:
    Engine m_Engine;
    Fueltank m_Fueltank;

    int m_MaxSeating;
    string m_brand;
    int m_year;

public:
    AUDI_Car(string model, int year, int maxSeating) {
        m_brand = "AUDI_" + model;
        m_year = year;
        m_MaxSeating = maxSeating;
        cout << "Constructing " << m_brand << endl;
    }

    string get_brand() const {
        return m_brand;
    }

    int get_Gas_grade() const {
        return m_Fueltank.GetGasGrade();
    }

    void set_Gas_grade(int gasGrade) {
        if (gasGrade >= 92 && gasGrade <= 98) {
            m_Fueltank.SetGasGrade(gasGrade);
        } else {
            cout << "Invalid gas grade: " << gasGrade << endl;
        }
    }

    void fuel_up(int amount, int gasGrade) {
        m_Fueltank.Refuel(amount, gasGrade);
    }
};

int main() {
    AUDI_Car car_2("A1", 2021, 2);
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.set_Gas_grade(95);
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.fuel_up(300, 95);
    return 0;
}
