#include <iostream>
#include <vector>

int main() {
    int N;
    std::cout << "Enter N: ";
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    for (int i = 0; i < N / 2; i++) A[i] *= 2;
    for (int i = N / 2; i < N; i++) A[i] *= 3;

    for (int i = 0; i < N; i++) std::cout << A[i] << " ";

    return 0;
}
