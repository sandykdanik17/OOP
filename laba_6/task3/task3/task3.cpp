#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Student {
protected:
    string name;
    int age;
    string university;

public:
    Student() : name(""), age(0), university("") {
        cout << "Створено об'єкт Student" << endl;
    }

    virtual ~Student() {
        cout << "Знищено об'єкт Student" << endl;
    }

    friend istream& operator>>(istream& in, Student& s) {
        cout << "Введіть ім'я студента: ";
        getline(in, s.name);
        cout << "Введіть вік: ";
        in >> s.age;
        in.ignore();
        cout << "Введіть назву університету: ";
        getline(in, s.university);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "Ім'я: " << s.name << "\nВік: " << s.age << "\nУніверситет: " << s.university;
        return out;
    }
};

class Parent {
protected:
    int childrenCount;
    bool isMarried;

public:
    Parent() : childrenCount(0), isMarried(false) {
        cout << "Створено об'єкт Parent" << endl;
    }

    virtual ~Parent() {
        cout << "Знищено об'єкт Parent" << endl;
    }

    friend istream& operator>>(istream& in, Parent& p) {
        cout << "Введіть кількість дітей: ";
        in >> p.childrenCount;
        cout << "Одружений (1 - так, 0 - ні): ";
        in >> p.isMarried;
        in.ignore();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Parent& p) {
        out << "Кількість дітей: " << p.childrenCount << "\nСімейний статус: " << (p.isMarried ? "Одружений" : "Неодружений");
        return out;
    }
};

class StudentParent : public Student, public Parent {
public:
    StudentParent() {
        cout << "Створено об'єкт StudentParent" << endl;
    }

    ~StudentParent() override {
        cout << "Знищено об'єкт StudentParent" << endl;
    }

    void displayInfo() const {
        cout << "\n[Інформація про Студента-Батька]" << endl;
        cout << static_cast<const Student&>(*this) << endl;
        cout << static_cast<const Parent&>(*this) << endl;
    }
};


void manualTest() {
    cout << "\n=== Тест ручного введення ===\n";
    StudentParent sp;
    cin >> static_cast<Student&>(sp);
    cin >> static_cast<Parent&>(sp);
    sp.displayInfo();
}

void arrayTest() {
    cout << "\n=== Тест масиву об'єктів ===\n";
    StudentParent arr[2];

    for (int i = 0; i < 2; ++i) {
        cout << "\nОб'єкт #" << i + 1 << ":\n";
        cin >> static_cast<Student&>(arr[i]);
        cin >> static_cast<Parent&>(arr[i]);
    }

    for (int i = 0; i < 2; ++i) {
        cout << "\nІнформація про об'єкт #" << i + 1 << ":\n";
        arr[i].displayInfo();
    }
}

void pointerTest() {
    cout << "\n=== Тест через покажчик ===\n";
    StudentParent* ptr = new StudentParent();
    cin >> static_cast<Student&>(*ptr);
    cin >> static_cast<Parent&>(*ptr);
    ptr->displayInfo();
    delete ptr;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    manualTest();
    arrayTest();
    pointerTest();
    return 0;
}
