#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

class Date {
private:
    int day, month, year;
    static const string months[12];

    bool isValid(int d, int m, int y) {
        return (y >= 0 && m >= 1 && m <= 12 && d >= 1 && d <= 31);
    }

public:
    Date(int d = 1, int m = 1, int y = 2000) { setDate(d, m, y); }

    void setDate(int d, int m, int y) {
        if (isValid(d, m, y)) {
            day = d; month = m; year = y;
        }
        else {
            cout << "Некоректна дата! Встановлено 1.01.2000" << endl;
            day = 1; month = 1; year = 2000;
        }
    }

    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    void printLongFormat() {
        cout << day << " " << months[month - 1] << " " << year << " року" << endl;
    }

    void printShortFormat() {
        cout << setfill('0') << setw(2) << day << "." << setw(2) << month << "." << year << endl;
    }

    void inputFromKeyboard() {
        int d, m, y;
        cout << "Введіть день, місяць і рік: ";
        cin >> d >> m >> y;
        setDate(d, m, y);
    }

    void inputFromFile(const string& filename) {
        ifstream file(filename);
        if (file) {
            int d, m, y;
            file >> d >> m >> y;
            setDate(d, m, y);
            file.close();
        }
        else {
            cout << "Помилка відкриття файлу!" << endl;
        }
    }

    void generateRandomDate() {
        srand(time(0));
        int d = rand() % 31 + 1;
        int m = rand() % 12 + 1;
        int y = rand() % 2024 + 1;
        setDate(d, m, y);
    }
};

const string Date::months[12] = { "січня", "лютого", "березня", "квітня", "травня", "червня",
                                 "липня", "серпня", "вересня", "жовтня", "листопада", "грудня" };

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Date date1;
    cout << "Дата за замовчуванням:" << endl;
    date1.printLongFormat();
    date1.printShortFormat();

    Date date2;
    cout << "\nВведення дати з клавіатури:" << endl;
    date2.inputFromKeyboard();
    date2.printLongFormat();
    date2.printShortFormat();

    Date date3;
    cout << "\nВведення дати з файлу:" << endl;
    date3.inputFromFile("date.txt");
    date3.printLongFormat();
    date3.printShortFormat();

    Date date4;
    cout << "\nГенерація випадкової дати:" << endl;
    date4.generateRandomDate();
    date4.printLongFormat();
    date4.printShortFormat();

    return 0;
}
