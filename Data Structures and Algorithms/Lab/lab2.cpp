#include <iostream>
#include <cassert>
using namespace std;

template<class hbi>

class linkedLists
{
private:
	struct Node
	{
		hbi item;
		Node *next;
	};
	int length;
	Node *head, *tail;

public:
	
linkedLists() 	{
	head, tail=NULL;
	length=0;
}

 	bool isEmpty()
	{
		return (length == 0);
	}

	void Deleting()
	{
		if (isEmpty())
			cout << "Empty List" << endl;
		else if (length == 1)
		{
			delete head;
			tail = NULL;
			length = 0;
		}
		else
		{
			Node *current = head;
			head = head->next;
			delete current;//free(current)
			length--;
		}
	}

	void insert(hbi item)
	{
		Node *newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (length == 0)
			tail = head = newNode;
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}

	void display()
	{
		Node*cur = head;
		cout << "Current list is: [ ";
		while (cur!=NULL)
		{
			cout << cur->item<<" ";
			cur = cur->next;
		}cout << "]" << endl;
	}

	void search(hbi item)
	{
		Node*cur = head;
		bool flag = true;
		while (cur != NULL)
		{
			if (cur->item == item)
			{
				cout << "The element you entered: " << item << " found in the list." << endl;
				flag = false;
				break;
			}
			cur = cur->next;
		}
		if(flag)
			cout << "The element you entered: " << item << " not found in the list." << endl;

	}

};

int main()
{
    int choice;
    int z;

    cout << "=====================================================" << endl;
    cout << "================ By Mustafa Eftekin =================" << endl;
    cout << " " << endl;
    cout << "       ~~ WELCOME to Linked List program ~~ " << endl;
    cout << " " << endl;

    linkedLists<int> linkedList;
    for (int i = 1; i <= 25; i++)
        linkedList.insert(i);

    while (true) {
        cout << "Select and Enter Your Choice from the Menu :" << endl;
        cout << "1. Add" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Print" << endl;
        cout << "5. Exit" << endl;
        cout << "=====================================================" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            linkedList.display();
            cout << "Enter the element you want to add to the list." << endl;
            cin >> z;
            linkedList.insert(z);
            linkedList.display();
            cout << "Successfully added." << endl;
            break;
        case 2:
            cout << "The first element of the list is deleted." << endl;
            linkedList.Deleting();
            linkedList.display();
            break;
        case 3:
            cout << "Enter the element you want to search for in the list." << endl;
            cin >> z;
            linkedList.search(z);
            linkedList.display();
            break;
        case 4:
            linkedList.display();
            break;
        case 5:
            cout << "Exiting the program." << endl;
            return 0; // Programdan çıkış yap
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
