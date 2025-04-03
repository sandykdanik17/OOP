#include <iostream>
#include <cstring>
#include <locale>
#include <Windows.h>

using namespace std;

const int MAX_ITEMS = 100; 

class Warehouse {
private:
    struct Item {
        char name[50]; 
        int inventoryNumber; 
    };

    Item items[MAX_ITEMS]; 
    int itemCount; 
    int CodeError; 

public:
    Warehouse() : itemCount(0), CodeError(0) {}

    // Додавання товару
    void addItem(const char* name, int number) {
        if (itemCount < MAX_ITEMS) {
            strcpy_s(items[itemCount].name, name);
            items[itemCount].inventoryNumber = number;
            itemCount++;
        }
        else {
            cout << "Помилка: склад заповнений!" << endl;
        }
    }

    // Пошук інвентарного номера за назвою
    int findInventoryNumber(const char* name) {
        for (int i = 0; i < itemCount; i++) {
            if (strcmp(items[i].name, name) == 0) {
                CodeError = 0; 
                return items[i].inventoryNumber;
            }
        }
        CodeError = -1; 
        return -1;
    }

    
    int operator[](const char* name) {
        return findInventoryNumber(name);
    }

    
    int getCodeError() {
        return CodeError;
    }

    
    friend istream& operator>>(istream& in, Warehouse& w) {
        if (w.itemCount < MAX_ITEMS) {
            cout << "Введіть назву товару: ";
            in.ignore(); 
            in.getline(w.items[w.itemCount].name, 50);
            cout << "Введіть інвентарний номер: ";
            in >> w.items[w.itemCount].inventoryNumber;
            w.itemCount++;
        }
        else {
            cout << "Помилка: склад заповнений!" << endl;
        }
        return in;
    }

    
    friend ostream& operator<<(ostream& out, const Warehouse& w) {
        out << "Список товарів на складі:\n";
        for (int i = 0; i < w.itemCount; i++) {
            out << "Назва: " << w.items[i].name << ", Інвентарний номер: " << w.items[i].inventoryNumber << endl;
        }
        return out;
    }
};


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, ""); 
    Warehouse warehouse;

    
    warehouse.addItem("Ноутбук", 101);
    warehouse.addItem("Смартфон", 102);
    warehouse.addItem("Мишка", 103);

    
    cout << warehouse;

    
    cout << "Інвентарний номер 'Смартфон': " << warehouse["Смартфон"] << endl;

   
    int num = warehouse["Телевізор"];
    if (warehouse.getCodeError() == -1) {
        cout << "Товар не знайдено!" << endl;
    }

    
    cin >> warehouse;

    
    cout << warehouse;

    system("pause"); 
    return 0;
}
