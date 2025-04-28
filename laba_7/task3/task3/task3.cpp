#include <iostream>
#include <windows.h>
using namespace std;

template <typename T, int SIZE = 10>
class Array {
    T arr[SIZE];
public:
    Array() {
        for (int i = 0; i < SIZE; i++)
            arr[i] = 0;
    }

    ~Array() {
        
    }

    T& operator[](int index) {
        return arr[index];
    }

    Array<T, SIZE>& operator=(const Array<T, SIZE>& other) {
        for (int i = 0; i < SIZE; i++)
            arr[i] = other.arr[i];
        return *this;
    }

    Array<T, SIZE> operator+(const Array<T, SIZE>& other) {
        Array<T, SIZE> res;
        for (int i = 0; i < SIZE; i++)
            res[i] = arr[i] + other.arr[i];
        return res;
    }

    Array<T, SIZE>& operator+=(const Array<T, SIZE>& other) {
        for (int i = 0; i < SIZE; i++)
            arr[i] += other.arr[i];
        return *this;
    }

    Array<T, SIZE> operator-(const Array<T, SIZE>& other) {
        Array<T, SIZE> res;
        for (int i = 0; i < SIZE; i++)
            res[i] = arr[i] - other.arr[i];
        return res;
    }

    Array<T, SIZE>& operator-=(const Array<T, SIZE>& other) {
        for (int i = 0; i < SIZE; i++)
            arr[i] -= other.arr[i];
        return *this;
    }

    void print() {
        for (int i = 0; i < SIZE; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void testArray() {
    Array<int, 5> a, b;
    cout << "Введіть елементи для масиву A:\n";
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    cout << "Введіть елементи для масиву B:\n";
    for (int i = 0; i < 5; i++) {
        cin >> b[i];
    }

    cout << "Масив A:\n"; a.print();
    cout << "Масив B:\n"; b.print();

    Array<int, 5> c = a + b;
    cout << "A + B:\n"; c.print();

    a += b;
    cout << "A += B:\n"; a.print();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Завдання 3.1\n";
    testArray();
    return 0;
}
