#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
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

    
    void setName(const string& n) { name = n; }
    void setAge(int a) { age = a; }
    string getName() const { return name; }
    int getAge() const { return age; }

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

    
    void setUniversity(const string& u) { university = u; }
    void setCourse(int c) { course = c; }
    string getUniversity() const { return university; }
    int getCourse() const { return course; }

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


string randomName() {
    const string names[] = { "Іван", "Марія", "Олег", "Олена", "Андрій" };
    return names[rand() % 5];
}

string randomUniversity() {
    const string universities[] = { "КНУ", "ЛПНУ", "ХНУРЕ", "КПІ", "ЛНУ" };
    return universities[rand() % 5];
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned>(time(0)));

    Person p1;
    cout << "Введення вручну для Person\n";
    cin >> p1;
    cout << "\nВведені дані:\n" << p1 << endl;

    cout << "\nЗчитування з файлу для Person\n";
    ifstream finPerson("input_person.txt");
    if (finPerson.is_open()) {
        string name;
        int age;
        finPerson >> name >> age;
        p1.setName(name);
        p1.setAge(age);
        finPerson.close();
        cout << "Дані з файлу:\n" << p1 << endl;
    }
    else {
        cout << "Не вдалося відкрити файл input_person.txt!\n";
    }

    cout << "\nГенерація випадкових даних для Person\n";
    p1.setName(randomName());
    p1.setAge(rand() % 60 + 18);
    cout << p1 << endl;

    Student s1;
    cout << "\nВведення вручну для Student\n";
    cin >> s1;
    cout << "\nВведені дані:\n" << s1 << endl;

    cout << "\nЗчитування з файлу для Student\n";
    ifstream finStudent("input_student.txt");
    if (finStudent.is_open()) {
        string name, university;
        int age, course;
        finStudent >> name >> age >> university >> course;
        s1.setName(name);
        s1.setAge(age);
        s1.setUniversity(university);
        s1.setCourse(course);
        finStudent.close();
        cout << "Дані з файлу:\n" << s1 << endl;
    }
    else {
        cout << "Не вдалося відкрити файл input_student.txt!\n";
    }

    cout << "\nГенерація випадкових даних для Student\n";
    s1.setName(randomName());
    s1.setAge(rand() % 60 + 18);
    s1.setUniversity(randomUniversity());
    s1.setCourse(rand() % 6 + 1);
    cout << s1 << endl;

    return 0;
}
