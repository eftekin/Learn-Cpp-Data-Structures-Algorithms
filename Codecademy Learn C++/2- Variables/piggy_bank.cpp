#include <iostream>

int main()
{

    double pesos;
    double reais;
    double soles;
    double dollars;

    std::cout << "Enter number of Colombian Pesos: ";
    std::cin >> pesos;
    std::cout << "Enter number of Brazilian Reais: ";
    std::cin >> reais;
    std::cout << "Enter number of Peruvian Soles:  ";
    std::cin >> soles;

    // As of Nov. 7th, 2023:
    // Pesos conversion rate: 0.057
    // Reais conversion rate: 0.20
    // Soles conversion rate: 0.27

    double pesos_rate = 0.057;
    double reais_rate = 0.20;
    double soles_rate = 0.27;

    dollars = (pesos_rate * pesos) + (reais_rate * reais) + (soles_rate * soles);

    std::cout << "US Dollars = $" << dollars << "\n";
}