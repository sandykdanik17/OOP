#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Button {
private:
    int size;

public:
    Button(int s = 0) : size(s) {}

    void setSize(int s) { size = s; }

    int getSize() const { return size; }
};

class Window {
protected:
    int x, y;
    Button button;

public:
    Window(int x_ = 0, int y_ = 0, int bSize = 0)
        : x(x_), y(y_), button(bSize) {
    }

    virtual void print() const {
        cout << "Координати вікна: (" << x << "," << y << "), розмір кнопки: " << button.getSize() << endl;
    }
};

class MenuWindow : public Window {
private:
    string menuButton;

public:
    MenuWindow(int x_, int y_, int bSize, const string& label)
        : Window(x_, y_, bSize), menuButton(label) {
    }

    void print() const override {
        Window::print();
        cout << "Кнопка меню: " << menuButton << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int x, y, size;
    string label;

    cout << "--- Введення даних для вікна з кнопкою меню ---\n";
    cout << "Координата X: ";
    cin >> x;
    cout << "Координата Y: ";
    cin >> y;
    cout << "Розмір кнопки: ";
    cin >> size;

    cin.ignore(); // очищення буфера після вводу чисел
    cout << "Текст кнопки меню: ";
    getline(cin, label); // вводимо рядок з пробілами

    MenuWindow mw(x, y, size, label);
    cout << "\n--- Інформація про вікно ---\n";
    mw.print();

    return 0;
}
