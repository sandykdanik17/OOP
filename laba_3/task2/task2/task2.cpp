#include <iostream>
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

    Vector(int s, int val) : size(s), state(0) {
        data = new (std::nothrow) int[s];
        if (!data) {
            state = 1;
        }
        else {
            for (int i = 0; i < s; i++) data[i] = val;
        }
        objectCount++;
    }

    // Конструктор копіювання
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

    // Оператор присвоєння
    Vector& operator=(const Vector& other) {
        if (this == &other) return *this;
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
        return *this;
    }

    // Деструктор
    ~Vector() {
        delete[] data;
        objectCount--;
    }

    // Функція присвоєння значення
    void setElement(int index, int value = 0) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
        else {
            state = 1;
            std::cout << "Помилка: індекс виходить за межі масиву!" << std::endl;
        }
    }

    // Функція отримання значення
    int getElement(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            std::cout << "Помилка: індекс виходить за межі масиву!" << std::endl;
            return 0;
        }
    }

    // Функція друку
    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Операції додавання і віднімання
    Vector operator+(const Vector& other) const {
        int newSize = (size < other.size) ? size : other.size;
        Vector result(newSize);
        for (int i = 0; i < newSize; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    Vector operator-(const Vector& other) const {
        int newSize = (size < other.size) ? size : other.size;
        Vector result(newSize);
        for (int i = 0; i < newSize; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Множення на ціле число
    Vector operator*(short scalar) const {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    // Функції порівняння
    bool operator==(const Vector& other) const {
        if (size != other.size) return false;
        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    bool operator<(const Vector& other) const {
        return size < other.size;
    }

    bool operator>(const Vector& other) const {
        return size > other.size;
    }

    // Статична функція підрахунку об'єктів
    static int getObjectCount() {
        return objectCount;
    }
};

int Vector::objectCount = 0;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Vector v1;
    Vector v2(5);
    Vector v3(5, 10);

    v1.print();
    v2.print();
    v3.print();

    v2.setElement(2, 50);
    std::cout << "Елемент за індексом 2 у v2: " << v2.getElement(2) << std::endl;

    Vector v4 = v2 + v3;
    v4.print();

    Vector v5 = v3 * 2;
    v5.print();

    std::cout << "Кількість об'єктів Vector: " << Vector::getObjectCount() << std::endl;

    return 0;
}