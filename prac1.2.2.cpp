#include <iostream>
using namespace std;

struct Book
{
    int id;
    char title[30];
    char author[30];
    int copies;
};

void addBook(Book &b)
{
    cout << "Enter Book ID: ";
    cin >> b.id;
    cout << "Enter Title: ";
    cin >> b.title;
    cout << "Enter Author: ";
    cin >> b.author;
    cout << "Enter Copies: ";
    cin >> b.copies;
}

void issueBook(Book &b)
{
    if (b.copies > 0)
    {
        b.copies--;
        cout << "Book issued successfully.\n";
    }
    else
    {
        cout << "No copies available.\n";
    }
}

void returnBook(Book &b)
{
    b.copies++;
    cout << "Book returned successfully.\n";
}

void displayBook(Book b)
{
    cout << "\nBook ID: " << b.id
         << "\nTitle: " << b.title
         << "\nAuthor: " << b.author
         << "\nCopies: " << b.copies << endl;
}

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
            addBook(b[total]);
            total++;
            break;

        case 2:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            found = false;
            for (int i = 0; i < total; i++)
            {
                if (b[i].id == id)
                {
                    issueBook(b[i]);
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
                if (b[i].id == id)
                {
                    returnBook(b[i]);
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
                    displayBook(b[i]);
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
