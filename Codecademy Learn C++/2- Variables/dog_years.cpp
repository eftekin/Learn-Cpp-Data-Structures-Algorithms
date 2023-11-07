#include <iostream>
// Note: This version of the program is for dogs older than 2 years old.

int main()
{
    int dog_age = 5;
    int early_years = 21;                        // The first two years of a dog’s life count as 21 human years.
    int later_years = (dog_age - 2) * 4;         // Each following year counts as 4 human years.
    int human_years = early_years + later_years; // Your dog's age in human years

    std::cout << "My name is Gila! Ruff ruff, I am " << human_years << " years old in human years.\n";
}