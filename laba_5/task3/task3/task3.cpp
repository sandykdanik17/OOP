#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "NoName", int a = 0) : name(n), age(a) {}

    Person(const Person& other) : name(other.name), age(other.age) {}

    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    virtual ~Person() {}

    friend istream& operator>>(istream& in, Person& p);
    friend ostream& operator<<(ostream& out, const Person& p);
};

istream& operator>>(istream& in, Person& p) {
    cout << "Введіть ім'я: ";
    in >> p.name;
    cout << "Введіть вік: ";
    in >> p.age;
    return in;
}

ostream& operator<<(ostream& out, const Person& p) {
    out << "Ім'я: " << p.name << ", Вік: " << p.age;
    return out;
}

class Student : public Person {
private:
    string university;
    int course;

public:
    Student(string n = "NoName", int a = 0, string u = "Unknown", int c = 1)
        : Person(n, a), university(u), course(c) {
    }

    Student(const Student& other)
        : Person(other), university(other.university), course(other.course) {
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            Person::operator=(other);
            university = other.university;
            course = other.course;
        }
        return *this;
    }

    ~Student() override {}

    friend istream& operator>>(istream& in, Student& s);
    friend ostream& operator<<(ostream& out, const Student& s);
};

istream& operator>>(istream& in, Student& s) {
    in >> static_cast<Person&>(s);
    cout << "Введіть університет: ";
    in >> s.university;
    cout << "Введіть курс: ";
    in >> s.course;
    return in;
}

ostream& operator<<(ostream& out, const Student& s) {
    out << static_cast<const Person&>(s)
        << ", Університет: " << s.university
        << ", Курс: " << s.course;
    return out;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student s;
    cout << "--- Введення студента ---\n";
    cin >> s;
    cout << "\n--- Введені дані ---\n" << s << endl;

    return 0;
}
