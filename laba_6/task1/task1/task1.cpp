#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class A1 {
protected:
    int value;
public:
    A1() : value(0) { cout << "A1 створено\n"; }
    A1(int v) : value(v) { cout << "A1(int) створено\n"; }
    virtual ~A1() { cout << "A1 знищено\n"; }
    virtual void show() { cout << "A1 значення: " << value << endl; }
};

class B1 : public A1 {
public:
    B1() { cout << "B1 створено\n"; }
    B1(int v) : A1(v) { cout << "B1(int) створено\n"; }
    ~B1() { cout << "B1 знищено\n"; }
    void show() override { cout << "B1 -> "; A1::show(); }
};

class B2 : public A1 {
public:
    B2() { cout << "B2 створено\n"; }
    B2(int v) : A1(v) { cout << "B2(int) створено\n"; }
    ~B2() { cout << "B2 знищено\n"; }
    void show() override { cout << "B2 -> "; A1::show(); }
};

class C1 : public B1, public B2 {
public:
    C1() { cout << "C1 створено (НЕ віртуальний)\n"; }
    C1(int v1, int v2) : B1(v1), B2(v2) { cout << "C1(int, int) створено\n"; }
    ~C1() { cout << "C1 знищено\n"; }
    void show() {
        cout << "C1 з B1 і B2:\n";
        B1::show();
        B2::show();
    }
};

class A2 {
protected:
    int value;
public:
    A2() : value(0) { cout << "A2 створено\n"; }
    A2(int v) : value(v) { cout << "A2(int) створено\n"; }
    virtual ~A2() { cout << "A2 знищено\n"; }
    virtual void show() { cout << "A2 значення: " << value << endl; }
};

class D1 : virtual public A2 {
public:
    D1() { cout << "D1 створено\n"; }
    D1(int v) { value = v; cout << "D1(int) створено\n"; }
    ~D1() { cout << "D1 знищено\n"; }
    void show() override { cout << "D1 -> "; A2::show(); }
};

class D2 : virtual public A2 {
public:
    D2() { cout << "D2 створено\n"; }
    D2(int v) { value = v; cout << "D2(int) створено\n"; }
    ~D2() { cout << "D2 знищено\n"; }
    void show() override { cout << "D2 -> "; A2::show(); }
};

class E1 : public D1, public D2 {
public:
    E1() { cout << "E1 створено (ВІРТУАЛЬНИЙ)\n"; }
    E1(int v) { value = v; cout << "E1(int) створено\n"; }
    ~E1() { cout << "E1 знищено\n"; }
    void show() override {
        cout << "E1 спільно з A2:\n";
        A2::show();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int val1, val2;

    cout << "Без віртуального успадкування\n";
    cout << "Введіть два цілі числа для C1 (B1 та B2): ";
    cin >> val1 >> val2;
    C1 c1(val1, val2);
    c1.show();
    cout << "Розмір C1: " << sizeof(C1) << " байт\n\n";

    cout << "З віртуальним успадкуванням\n";
    cout << "Введіть одне ціле число для E1 (спільне для A2): ";
    cin >> val1;
    E1 e1(val1);
    e1.show();
    cout << "Розмір E1: " << sizeof(E1) << " байт\n";

    return 0;
}
