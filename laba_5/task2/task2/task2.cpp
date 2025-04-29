#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Button {
private:
    int size;

public:
    Button(int s = 0) : size(s) {
        cout << "Створено об'єкт Button\n";
    }

    void setSize(int s) { size = s; }
    int getSize() const { return size; }

    ~Button() {
        cout << "Знищено об'єкт Button\n";
    }
};

class Window {
protected:
    int x, y;
    Button button;

public:
    Window(int x_ = 0, int y_ = 0, int bSize = 0)
        : x(x_), y(y_), button(bSize) {
        cout << "Створено об'єкт Window\n";
    }

    virtual ~Window() {
        cout << "Знищено об'єкт Window\n";
    }

    virtual void print() const {
        cout << "Координати вікна: (" << x << "," << y << "), розмір кнопки: " << button.getSize() << endl;
    }
};

class MenuWindow : public Window {
private:
    string* menuButton;

public:
    MenuWindow(int x_, int y_, int bSize, const string& label)
        : Window(x_, y_, bSize) {
        menuButton = new string(label);
        cout << "Створено об'єкт MenuWindow\n";
    }

    ~MenuWindow() override {
        delete menuButton;
        cout << "Знищено об'єкт MenuWindow\n";
    }

    void print() const override {
        Window::print();
        cout << "Кнопка меню: " << *menuButton << endl;
    }
};


string randomMenuButton() {
    const string labels[] = { "Файл", "Правка", "Перегляд", "Довідка", "Налаштування" };
    return labels[rand() % 5];
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    int x, y, size;
    string label;

    
    cout << "Введення даних вручну для Window\n";
    cout << "Координата X: ";
    cin >> x;
    cout << "Координата Y: ";
    cin >> y;
    cout << "Розмір кнопки: ";
    cin >> size;

    Window w1(x, y, size);
    w1.print();

    
    cout << "\nЗчитування даних з файлу для Window\n";
    ifstream finWindow("input_window.txt");
    if (finWindow.is_open()) {
        finWindow >> x >> y >> size;
        finWindow.close();
        Window w2(x, y, size);
        w2.print();
    }
    else {
        cout << "Не вдалося відкрити файл input_window.txt!\n";
    }

    
    cout << "\nГенерація випадкових даних для Window\n";
    x = rand() % 801;  
    y = rand() % 601;  
    size = rand() % 101 + 20;  
    Window w3(x, y, size);
    w3.print();

    
    cout << "\nВведення даних вручну для MenuWindow\n";
    cout << "Координата X: ";
    cin >> x;
    cout << "Координата Y: ";
    cin >> y;
    cout << "Розмір кнопки: ";
    cin >> size;
    cin.ignore();
    cout << "Текст кнопки меню: ";
    getline(cin, label);

    MenuWindow mw1(x, y, size, label);
    mw1.print();

   
    cout << "\nЗчитування даних з файлу для MenuWindow\n";
    ifstream finMenu("input_menuwindow.txt");
    if (finMenu.is_open()) {
        getline(finMenu, label);
        finMenu >> x >> y >> size;
        finMenu.close();
        MenuWindow mw2(x, y, size, label);
        mw2.print();
    }
    else {
        cout << "Не вдалося відкрити файл input_menuwindow.txt!\n";
    }

    
    cout << "\nГенерація випадкових даних для MenuWindow\n";
    x = rand() % 801;
    y = rand() % 601;
    size = rand() % 101 + 20;
    label = randomMenuButton();
    MenuWindow mw3(x, y, size, label);
    mw3.print();

    return 0;
}
