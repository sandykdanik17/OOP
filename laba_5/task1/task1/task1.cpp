
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Car {
protected:
    string brand;
    int cylinders;
    int power;

public:
    Car() : brand("NoBrand"), cylinders(0), power(0) {}

    Car(string b, int c, int p) : brand(b), cylinders(c), power(p) {}

    virtual ~Car() {}

    void setBrand(const string& b) { brand = b; }

    void setPower(int p) { power = p; }

    virtual void print() const {
        cout << "Марка: " << brand << ", Циліндри: " << cylinders
            << ", Потужність: " << power << " к.с.\n";
    }
};

class Lorry : public Car {
private:
    double capacity;

public:
    Lorry() : Car(), capacity(0) {}

    Lorry(string b, int c, int p, double cap)
        : Car(b, c, p), capacity(cap) {
    }

    ~Lorry() override {}

    void setBrand(const string& b) { brand = b + " (Lorry)"; }

    void setCapacity(double cap) { capacity = cap; }

    void print() const override {
        Car::print();
        cout << "Вантажопідйомність: " << capacity << " т\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string brand;
    int cylinders, power;
    double capacity;

    cout << "--- Введення даних для машини ---\n";
    cout << "Марка: ";
    cin >> brand;
    cout << "Кількість циліндрів: ";
    cin >> cylinders;
    cout << "Потужність: ";
    cin >> power;

    Car car(brand, cylinders, power);
    car.print();

    cout << "\n--- Введення даних для вантажівки ---\n";
    cout << "Марка: ";
    cin >> brand;
    cout << "Кількість циліндрів: ";
    cin >> cylinders;
    cout << "Потужність: ";
    cin >> power;
    cout << "Вантажопідйомність (т): ";
    cin >> capacity;

    Lorry lorry(brand, cylinders, power, capacity);
    lorry.print();

    return 0;
}


    

   