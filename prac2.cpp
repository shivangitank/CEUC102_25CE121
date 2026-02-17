#include <iostream>
#include <cstring>
using namespace std;

class library
{
    int book_id;
    char author[15];
    char title[15];
    int copies;

public:
    void set_data()
    {
        cout << "Enter book id: ";
        cin >> book_id;

        cout << "Enter author name: ";
        cin >> author;

        cout << "Enter title of the book: ";
        cin >> title;

        cout << "Enter number of copies: ";
        cin >> copies;
    }

    void issue_book()
    {
        if (copies > 0)
        {
            copies--;
            cout << "Book issued successfully.\n";
        }
        else
        {
            cout << "Copies are not available!!\n";
        }
    }

    void add_book()
    {
        copies++;
        cout << "Copies added successfully!!\n";
    }

    void return_book()
    {
        copies++;
        cout << "Book returned successfully!\n";
    }

    void display_book()
    {
        cout << "\nBook ID: " << book_id
             << "\nAuthor: " << author
             << "\nTitle: " << title
             << "\nCopies Available: " << copies << endl;
    }
};

int main()
{
    library b;
    int choice;

    do
    {
        cout << "\n---- Welcome to our Library ----\n";
        cout << "1. Enter book details\n";
        cout << "2. Add book copy\n";
        cout << "3. Issue book\n";
        cout << "4. Return book\n";
        cout << "5. Display book details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b.set_data();
            break;

        case 2:
            b.add_book();
            break;

        case 3:
            b.issue_book();
            break;

        case 4:
            b.return_book();
            break;

        case 5:
            b.display_book();
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
