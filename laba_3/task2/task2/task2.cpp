#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

class Vector {
private:
    int* data;
    int size;
    int state;
    static int objectCount;

public:
    // Конструктори
    Vector() : size(1), state(0) {
        data = new (std::nothrow) int[1];
        if (!data) {
            state = 1;
        }
        else {
            data[0] = 0;
        }
        objectCount++;
    }

    Vector(int s) : size(s), state(0) {
        data = new (std::nothrow) int[s];
        if (!data) {
            state = 1;
        }
        else {
            for (int i = 0; i < s; i++) data[i] = 0;
        }
        objectCount++;
    }

    Vector(int s, int value) : size(s), state(0) {
        data = new (std::nothrow) int[s];
        if (!data) {
            state = 1;
        }
        else {
            for (int i = 0; i < s; i++) data[i] = value;
        }
        objectCount++;
    }

    Vector(const Vector& other) : size(other.size), state(other.state) {
        data = new (std::nothrow) int[size];
        if (!data) {
            state = 1;
        }
        else {
            for (int i = 0; i < size; i++) data[i] = other.data[i];
        }
        objectCount++;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            state = other.state;
            data = new (std::nothrow) int[size];
            if (!data) {
                state = 1;
            }
            else {
                for (int i = 0; i < size; i++) data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~Vector() {
        delete[] data;
        objectCount--;
    }

    void setElement(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
        else {
            state = 2;
        }
    }

    int getElement(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        return -1;
    }

    void inputFromKeyboard() {
        std::cout << "Введіть " << size << " елемент(и) вектора: ";
        for (int i = 0; i < size; i++) {
            std::cin >> data[i];
        }
    }

    bool inputFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cout << "Помилка відкриття файлу!" << std::endl;
            return false;
        }
        for (int i = 0; i < size && file >> data[i]; i++);
        file.close();
        return true;
    }

    void inputRandom(int min, int max) {
        std::srand(std::time(nullptr));
        for (int i = 0; i < size; i++) {
            data[i] = min + std::rand() % (max - min + 1);
        }
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    Vector operator+(const Vector& other) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    Vector operator-(const Vector& other) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    Vector operator*(short num) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = this->data[i] * num;
        }
        return result;
    }

    bool operator==(const Vector& other) { return size == other.size; }
    bool operator<(const Vector& other) { return size < other.size; }
    bool operator>(const Vector& other) { return size > other.size; }
};

int Vector::objectCount = 0;

int main() {
    SetConsoleOutputCP(65001);

    Vector v1(5);
    v1.inputFromKeyboard();
    v1.print();

    Vector v2(5, 10);
    v2.print();

    Vector v3 = v1 + v2;
    v3.print();

    Vector v4 = v1 - v2;
    v4.print();

    Vector v5 = v1 * 2;
    v5.print();

    return 0;
}
