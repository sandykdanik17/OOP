#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Car {
protected:
    string brand;
    int cylinders;
    int power;

public:
    Car() : brand("NoBrand"), cylinders(0), power(0) {
        cout << "Створено об'єкт Car\n";
    }

    Car(string b, int c, int p) : brand(b), cylinders(c), power(p) {
        cout << "Створено об'єкт Car з параметрами\n";
    }

    virtual ~Car() {
        cout << "Знищено об'єкт Car\n";
    }

    void setBrand(const string& b) { brand = b; }
    void setCylinders(int c) { cylinders = c; }
    void setPower(int p) { power = p; }

    virtual void print() const {
        cout << "Марка: " << brand << ", Циліндри: " << cylinders << ", Потужність: " << power << " к.с.\n";
    }
};

class Lorry : public Car {
private:
    double capacity;

public:
    Lorry() : Car(), capacity(0) {
        cout << "Створено об'єкт Lorry\n";
    }

    Lorry(string b, int c, int p, double cap) : Car(b, c, p), capacity(cap) {
        cout << "Створено об'єкт Lorry з параметрами\n";
    }

    ~Lorry() override {
        cout << "Знищено об'єкт Lorry\n";
    }

    void setCapacity(double cap) { capacity = cap; }

    void print() const override {
        Car::print();
        cout << "Вантажопідйомність: " << capacity << " т\n";
    }
};

string randomBrand() {
    const string brands[] = { "Toyota", "Ford", "BMW", "Mercedes", "Audi" };
    return brands[rand() % 5];
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    string brand;
    int cylinders, power;
    double capacity;

    
    cout << "Введення даних вручну для Car\n";
    cout << "Марка: ";
    cin >> brand;
    cout << "Кількість циліндрів: ";
    cin >> cylinders;
    cout << "Потужність: ";
    cin >> power;

    Car car1(brand, cylinders, power);
    car1.print();

    
    cout << "\nЗчитування даних з файлу для Car\n";
    ifstream finCar("input_car.txt");
    if (finCar.is_open()) {
        finCar >> brand >> cylinders >> power;
        finCar.close();
        Car car2(brand, cylinders, power);
        car2.print();
    }
    else {
        cout << "Не вдалося відкрити файл input_car.txt!\n";
    }

    
    cout << "\nГенерація випадкових даних для Car\n";
    brand = randomBrand();
    cylinders = rand() % 12 + 4;
    power = rand() % 300 + 50;
    Car car3(brand, cylinders, power);
    car3.print();

    
    cout << "\nВведення даних вручну для Lorry\n";
    cout << "Марка: ";
    cin >> brand;
    cout << "Кількість циліндрів: ";
    cin >> cylinders;
    cout << "Потужність: ";
    cin >> power;
    cout << "Вантажопідйомність (т): ";
    cin >> capacity;

    Lorry lorry1(brand, cylinders, power, capacity);
    lorry1.print();

   
    cout << "\nЗчитування даних з файлу для Lorry\n";
    ifstream finLorry("input_lorry.txt");
    if (finLorry.is_open()) {
        finLorry >> brand >> cylinders >> power >> capacity;
        finLorry.close();
        Lorry lorry2(brand, cylinders, power, capacity);
        lorry2.print();
    }
    else {
        cout << "Не вдалося відкрити файл input_lorry.txt!\n";
    }

   
    cout << "\nГенерація випадкових даних для Lorry\n";
    brand = randomBrand();
    cylinders = rand() % 12 + 4;
    power = rand() % 300 + 50;
    capacity = (rand() % 20000) / 1000.0;
    Lorry lorry3(brand, cylinders, power, capacity);
    lorry3.print();

    return 0;
}
