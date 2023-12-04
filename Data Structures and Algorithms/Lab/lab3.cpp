#include <iostream>
#include <cstring>

void showMenu()
{
    std::cout << "~~ WELCOME Sorting Algorithms program ~~" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Select and Enter Your Choice from the Menu:" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "O (n * n) Sorting Algorithms programs:" << std::endl;
    std::cout << "1. Bubble Sort (By Age)" << std::endl;
    std::cout << "2. Insertion Sort (By Name)" << std::endl;
    std::cout << "3. Selection Sort (By Last Name)" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

struct student
{
    char firstName[20];
    char lastName[20];
    unsigned int age;
    char gender;
    int level;
    student *next;
};

void insertStudent(student *&head, const char *firstName, const char *lastName, unsigned int age, char gender, int level)
{
    student *newStudent = new student;
    std::strncpy(newStudent->firstName, firstName, sizeof(newStudent->firstName));
    std::strncpy(newStudent->lastName, lastName, sizeof(newStudent->lastName));
    newStudent->age = age;
    newStudent->gender = gender;
    newStudent->level = level;
    newStudent->next = head;
    head = newStudent;
}

void printList(student *head)
{
    student *current = head;
    while (current != nullptr)
    {
        std::cout << "First Name: " << current->firstName << std::endl;
        std::cout << "Last Name: " << current->lastName << std::endl;
        std::cout << "Age: " << current->age << std::endl;
        std::cout << "Gender: " << current->gender << std::endl;
        std::cout << "Level: " << current->level << std::endl;
        std::cout << std::endl;
        current = current->next;
    }
}

void bubbleSortByAge(student *head)
{
    if (head == nullptr)
    {
        return; // Don't perform operations if the list is empty
    }

    student *current;
    student *last = nullptr;
    bool swapped;

    do
    {
        swapped = false;
        current = head;

        for (; current->next != last; current = current->next)
        {
            if (current->age > current->next->age)
            {
                // Swap elements based on age
                std::swap(current->firstName, current->next->firstName);
                std::swap(current->lastName, current->next->lastName);
                std::swap(current->age, current->next->age);
                std::swap(current->gender, current->next->gender);
                std::swap(current->level, current->next->level);
                swapped = true;
            }
        }
        last = current;
    } while (swapped);
}

void insertionSortByName(student *&head)
{
    if (head == nullptr)
    {
        return; // Don't perform operations if the list is empty
    }

    student *sorted = nullptr; // sorted
    student *current = head;

    while (current != nullptr)
    {
        student *next = current->next;
        if (sorted == nullptr || std::strcmp(current->firstName, sorted->firstName) < 0)
        {
            // If the sorted list is empty or the current student should be inserted at the beginning of the sorted list
            current->next = sorted;
            sorted = current;
        }
        else
        {
            // If the current student should be inserted at the end or in the middle of the sorted list
            student *currentSorted = sorted;
            while (currentSorted->next != nullptr && std::strcmp(current->firstName, currentSorted->next->firstName) >= 0)
            {
                currentSorted = currentSorted->next;
            }
            current->next = currentSorted->next;
            currentSorted->next = current;
        }
        current = next;
    }

    head = sorted; // The sorted list is set as the new starting point
}

void selectionSortByLastName(student *head)
{
    if (head == nullptr)
    {
        return; // Don't perform operations if the list is empty
    }

    student *current = head;

    while (current != nullptr)
    {
        student *minLastName = current;
        student *search = current->next;

        while (search != nullptr)
        {
            if (std::strcmp(search->lastName, minLastName->lastName) < 0)
            {
                minLastName = search;
            }
            search = search->next;
        }

        // Swap with the student having the minimum last name
        if (minLastName != current)
        {
            std::swap(current->firstName, minLastName->firstName);
            std::swap(current->lastName, minLastName->lastName);
            std::swap(current->age, minLastName->age);
            std::swap(current->gender, minLastName->gender);
            std::swap(current->level, minLastName->level);
        }

        current = current->next;
    }
}

int main()
{
    student *head = nullptr;

    char firstName[20];
    char lastName[20];
    unsigned int age;
    char gender;
    int level;

    char addMore;
    do
    {
        std::cout << "Enter First Name: ";
        std::cin >> firstName;
        std::cout << "Enter Last Name: ";
        std::cin >> lastName;
        std::cout << "Enter Age: ";
        std::cin >> age;
        std::cout << "Enter Gender (M/F): ";
        std::cin >> gender;
        std::cout << "Enter Level: ";
        std::cin >> level;

        insertStudent(head, firstName, lastName, age, gender, level);

        std::cout << "Do you want to add another student? (Y/N): \n";
        std::cin >> addMore;
    } while (addMore == 'Y' || addMore == 'y');

    int choice;
    char continueChoice;
    do
    {
        showMenu();
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        if (choice == 4)
        {
            break; // exit uygulamadan çıkmasını sağlar
        }

        switch (choice)
        {
        case 1:
            bubbleSortByAge(head);
            std::cout << "Students sorted by age:" << std::endl;
            break;
        case 2:
            insertionSortByName(head);
            std::cout << "Students sorted by name:" << std::endl;
            break;
        case 3:
            selectionSortByLastName(head);
            std::cout << "Students sorted by surname:" << std::endl;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }

        printList(head);

        std::cout << "Do you want to perform another operation? (Y/N): ";
        std::cin >> continueChoice;
    } while (continueChoice == 'Y' || continueChoice == 'y');

    return 0;
}