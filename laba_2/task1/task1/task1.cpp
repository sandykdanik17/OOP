﻿#include <iostream> 
using namespace std;

int main() {
    int a, b, c, d;

    cout << "Write down a, b, c, d: ";
    cin >> a >> b >> c >> d;

    // 127 * a  → (a << 7) - a
    int term_a = (a << 7) - a;

    // 32 * c → (c << 5)
    int term_c = (c << 5);

    // (127 * a + 32 * c) / 4096 → ((term_a + term_c) >> 12)
    int numerator = term_a + term_c;
    int fraction_part = numerator >> 12;

    // d * 1200 → (d << 10) + (d << 7) + (d << 5)
    int term_d = (d << 10) + (d << 7) + (d << 5);

    // b * 131 → (b << 7) + (b << 1) + b
    int term_b = (b << 7) + (b << 1) + b;

    // Повний вираз:
    // (127*a + 32*c)/4096 - d*1200 + b*131
    int result = fraction_part - term_d + term_b;

    cout << "Result: " << result << endl;
    return 0;
}
