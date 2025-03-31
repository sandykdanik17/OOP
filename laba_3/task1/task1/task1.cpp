#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

class Date {
private:
    int day, month, year;

public:
    Date(int d = 1, int m = 1, int y = 2000) {
        setDate(d, m, y);
    }

    void setDate(int d, int m, int y) {
        if (y >= 0 && m >= 1 && m <= 12 && d >= 1 && d <= 31) {
            day = d; month = m; year = y;
        }
        else {
            cout << "Некоректна дата!" << endl;
            day = 1; month = 1; year = 2000;
        }
    }

    void printLongFormat() {
        string months[] = { "січня", "лютого", "березня", "квітня", "травня", "червня", "липня", "серпня", "вересня", "жовтня", "листопада", "грудня" };
        cout << day << " " << months[month - 1] << " " << year << " року" << endl;
    }

    void printShortFormat() {
        cout << setfill('0') << setw(2) << day << "." << setw(2) << month << "." << year << endl;
    }
};

int main() {
    SetConsoleOutputCP(1251);

    Date date1;
    Date date2(5, 1, 2019);

    cout << "Дата за замовчуванням:" << endl;
    date1.printLongFormat();
    date1.printShortFormat();

    cout << "\nЗадана дата:" << endl;
    date2.printLongFormat();
    date2.printShortFormat();

    cout << "\nЗміна дати:" << endl;
    date1.setDate(31, 12, 2024);
    date1.printLongFormat();
    date1.printShortFormat();

    return 0;
}
