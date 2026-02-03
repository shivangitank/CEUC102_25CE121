#include <iostream>
using namespace std;

class Book
{
    int id;
    char title[30];
    char author[30];
    int copies;

public:
    void addBook()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter Copies: ";
        cin >> copies;
    }

    int getId()
    {
        return id;
    }

    void issueBook()
    {
        if (copies > 0)
        {
            copies--;
            cout << "Book issued successfully.\n";
        }
        else
        {
            cout << "No copies available.\n";
        }
    }

    void returnBook()
    {
        copies++;
        cout << "Book returned successfully.\n";
    }

    void displayBook()
    {
        cout << "\nBook ID: " << id
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nCopies: " << copies << endl;
    }
};

int main()
{
    Book b[50];
    int total = 0, choice, id;
    bool found;

    do
    {
        cout << "\n---- Library Menu ----\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book (by ID)\n";
        cout << "3. Return Book (by ID)\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b[total].addBook();
            total++;
            break;

        case 2:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            found = false;
            for (int i = 0; i < total; i++)
            {
                if (b[i].getId() == id)
                {
                    b[i].issueBook();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book ID not found.\n";
            break;

        case 3:
            cout << "Enter Book ID to return: ";
            cin >> id;
            found = false;
            for (int i = 0; i < total; i++)
            {
                if (b[i].getId() == id)
                {
                    b[i].returnBook();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book ID not found.\n";
            break;

        case 4:
            if (total == 0)
                cout << "No books available.\n";
            else
                for (int i = 0; i < total; i++)
                    b[i].displayBook();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
