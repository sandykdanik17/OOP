#include <iostream>
#include <Windows.h>
#include <vector>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    std::cout << "Введіть N: ";
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    int* pA = A.data(); 
    int firstNegativeIndex = -1;
    for (int i = 0; i < N; i++) {
        if (*(pA + i) < 0) {
            firstNegativeIndex = i;
            break;
        }
    }

    if (firstNegativeIndex == -1) {
        std::cout << "Немає від’ємних елементів." << std::endl;
        return 0;
    }

    int minEvenPositive = INT_MAX;
    int lastMinIndex = -1;
    for (int i = firstNegativeIndex + 1; i < N; i++) {
        if (*(pA + i) > 0 && *(pA + i) % 2 == 0) {
            if (*(pA + i) <= minEvenPositive) {
                minEvenPositive = *(pA + i);
                lastMinIndex = i;
            }
        }
    }

    if (lastMinIndex == -1) {
        std::cout << "Немає потрібних елементів." << std::endl;
    }
    else {
        std::cout << "Номер останнього мінімального парного додатного елемента: " << lastMinIndex << std::endl;
    }

    return 0;
}
