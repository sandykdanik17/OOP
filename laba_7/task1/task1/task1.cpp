#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

template <typename T>
int findLastIndex(T arr[], int size, T key) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) index = i;
    }
    return index;
}

template <>
int findLastIndex<char*>(char* arr[], int size, char* key) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], key) == 0) index = i;
    }
    return index;
}

template <typename T>
void inputFromKeyboard(T arr[], int size) {
    cout << "Введіть " << size << " елементів:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void testFindLastIndex() {
    const int size = 5;
    int arr[size];

    cout << "Введіть масив цілих чисел:\n";
    inputFromKeyboard(arr, size);

    cout << "Ваш масив: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    int key;
    cout << "Введіть значення для пошуку останнього індексу: ";
    cin >> key;

    cout << "Індекс останнього елемента " << key << ": " << findLastIndex(arr, size, key) << endl;

    
    char* sarr[size];
    cout << "Введіть масив рядків:\n";
    cin.ignore();
    for (int i = 0; i < size; i++) {
        char buffer[100];
        cout << "Введіть рядок #" << i + 1 << ": ";
        cin.getline(buffer, 100);
        sarr[i] = new char[strlen(buffer) + 1];
        strcpy(sarr[i], buffer);
    }

    char keyBuffer[100];
    cout << "Введіть рядок для пошуку останнього індексу: ";
    cin.getline(keyBuffer, 100);

    cout << "Індекс останнього '" << keyBuffer << "': " << findLastIndex(sarr, size, keyBuffer) << endl;

    
    for (int i = 0; i < size; i++) {
        delete[] sarr[i];
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Завдання 1.1\n";
    testFindLastIndex();
    return 0;
}
