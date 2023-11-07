#include <iostream>
#include <cmath>

int main()
{
    double a;
    double b;
    double c;

    std::cout << "Entar a: ";
    std::cin >> a;

    std::cout << "Entar b: ";
    std::cin >> b;

    std::cout << "Entar c: ";
    std::cin >> c;

    double root1 = (-b + std::sqrt(b * b - 4 * a * c)) / (2 * a);
    double root2 = (-b - std::sqrt(b * b - 4 * a * c)) / (2 * a);

    std::cout << "Root 1 is " << root1 << "\n";
    std::cout << "Root 2 is " << root2;
}