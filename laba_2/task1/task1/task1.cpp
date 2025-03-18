#include <iostream>

int main() {
    int a, b, c, d;

    std::cout << "Введіть a, b, c, d: ";
    std::cin >> a >> b >> c >> d;

    int result = ((a << 7) - a + (c << 5)) >> 12 - d * ((1 << 10) + (1 << 7) + (1 << 5) + (1 << 4) + (1 << 3)) + b * ((1 << 7) + (1 << 1) + 1);

    std::cout << "Результат: " << result << std::endl;

    return 0;
}