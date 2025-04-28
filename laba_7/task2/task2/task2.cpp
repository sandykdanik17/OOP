#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
using namespace std;

template <typename T>
void quickSort(T arr[], int left, int right) {
    int i = left, j = right;
    T pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            T tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

template <>
void quickSort<char*>(char* arr[], int left, int right) {
    int i = left, j = right;
    char* pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (strcmp(arr[i], pivot) < 0) i++;
        while (strcmp(arr[j], pivot) > 0) j--;
        if (i <= j) {
            char* tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

template <typename T>
void inputFromKeyboard(T arr[], int size) {
    cout << "Введіть " << size << " елементів:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

template <>
void inputFromKeyboard<char*>(char* arr[], int size) {
    char buffer[256];
    for (int i = 0; i < size; i++) {
        cout << "Введіть рядок #" << i + 1 << ": ";
        cin >> buffer;
        arr[i] = new char[strlen(buffer) + 1];
        strcpy_s(arr[i], strlen(buffer) + 1, buffer);
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

void testQuickSort() {
    const int size = 8;
    int arr[size];

    cout << "Введіть масив цілих чисел:\n";
    inputFromKeyboard(arr, size);

    cout << "Масив до сортування:\n";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);
    cout << "Масив після сортування:\n";
    printArray(arr, size);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Завдання 2.1\n";
    testQuickSort();
    return 0;
}
