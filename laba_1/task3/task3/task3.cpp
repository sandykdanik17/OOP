#include <iostream>
#include <Windows.h>
#include <vector>  

struct Point {
    double x, y;
};

// Функція для обчислення площі трикутника
double triangleArea(Point A, Point B, Point C) {
    return 0.5 * abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

// Функція для перевірки, чи точка всередині трикутника
bool isInsideTriangle(Point P, Point A, Point B, Point C) {
    double mainArea = triangleArea(A, B, C);
    double area1 = triangleArea(P, B, C);
    double area2 = triangleArea(A, P, C);
    double area3 = triangleArea(A, B, P);
    return (mainArea == (area1 + area2 + area3));
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, count = 0;
    std::cout << "Введіть кількість точок: ";
    std::cin >> n;

    std::vector<Point> points(n);  

    std::cout << "Введіть координати точок (x y):\n";
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    Point A, B, C;
    std::cout << "Введіть координати трикутника (Ax Ay Bx By Cx Cy): ";
    std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    for (int i = 0; i < n; i++) {
        if (isInsideTriangle(points[i], A, B, C)) {
            count++;
        }
    }

    std::cout << "Кількість точок всередині трикутника: " << count << std::endl;
    return 0;
}







