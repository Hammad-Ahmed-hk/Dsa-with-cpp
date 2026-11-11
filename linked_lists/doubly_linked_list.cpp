#include <iostream>
#include <string>

using namespace std;

// Structure to represent a book
struct Book {
    string title, author, ISBN;
    double price;
    int edition;
    Book* prev;
    Book* next;

    // Constructor for a new book
    Book(string t, string a, string i, double p, int e)
        : title(t), author(a), ISBN(i), price(p), edition(e), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List to manage the library
class Library {
private:
    Book* head;
    Book* tail;

public:
    // Constructor
    Library() : head(nullptr), tail(nullptr) {}

    // Add book at the start
    void addBookToStart(string title, string author, string ISBN, double price, int edition) {
        Book* newBook = new Book(title, author, ISBN, price, edition);
        if (!head) {
            head = tail = newBook;
        } else {
            newBook->next = head;
            head->prev = newBook;
            head = newBook;
        }
    }

    // Add book at the end
    void addBookToEnd(string title, string author, string ISBN, double price, int edition) {
        Book* newBook = new Book(title, author, ISBN, price, edition);
        if (!tail) {
            head = tail = newBook;
        } else {
            tail->next = newBook;
            newBook->prev = tail;
            tail = newBook;
        }
    }

    // Add book at a specific position
    void addBookAtPosition(string title, string author, string ISBN, double price, int edition, int position) {
        if (position <= 1) {
            addBookToStart(title, author, ISBN, price, edition);
            return;
        }

        Book* temp = head;
        int currentPos = 1;
        while (temp && currentPos < position - 1) {
            temp = temp->next;
            currentPos++;
        }

        if (!temp || !temp->next) {
            addBookToEnd(title, author, ISBN, price, edition);
        } else {
            Book* newBook = new Book(title, author, ISBN, price, edition);
            newBook->next = temp->next;
            newBook->prev = temp;
            temp->next->prev = newBook;
            temp->next = newBook;
        }
    }

    // Delete a book by position
    void deleteBookByPosition(int position) {
        if (!head) {
            cout << "Library is empty.\n";
            return;
        }

        Book* temp = head;
        if (position == 1) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
            delete temp;
            return;
        }

        int currentPos = 1;
        while (temp && currentPos < position) {
            temp = temp->next;
            currentPos++;
        }

        if (!temp) {
            cout << "Invalid position.\n";
            return;
        }

        if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    // Display books from start to end
    void displayFromStart() {
        if (!head) {
            cout << "No books in the library.\n";
            return;
        }

        Book* temp = head;
        while (temp) {
            cout << "Title: " << temp->title
                 << ", Author: " << temp->author
                 << ", ISBN: " << temp->ISBN
                 << ", Price: $" << temp->price
                 << ", Edition: " << temp->edition << "\n";
            temp = temp->next;
        }
    }

    // Destructor to free memory
    ~Library() {
        while (head) {
            Book* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Function to get book details from the user
void getBookDetails(string &title, string &author, string &ISBN, double &price, int &edition) {
    cout << "Enter title: "; cin.ignore(); getline(cin, title);
    cout << "Enter author: "; getline(cin, author);
    cout << "Enter ISBN: "; getline(cin, ISBN);
    cout << "Enter price: $"; cin >> price;
    cout << "Enter edition: "; cin >> edition;
}

// Main menu
int main() {
    Library library;
    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add book at start\n";
        cout << "2. Add book at end\n";
        cout << "3. Add book at position\n";
        cout << "4. Delete book by position\n";
        cout << "5. Display books\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        string title, author, ISBN;
        double price;
        int edition, position;

        switch (choice) {
            case 1:
                getBookDetails(title, author, ISBN, price, edition);
                library.addBookToStart(title, author, ISBN, price, edition);
                break;

            case 2:
                getBookDetails(title, author, ISBN, price, edition);
                library.addBookToEnd(title, author, ISBN, price, edition);
                break;

            case 3:
                cout << "Enter position: "; cin >> position;
                getBookDetails(title, author, ISBN, price, edition);
                library.addBookAtPosition(title, author, ISBN, price, edition, position);
                break;

            case 4:
                cout << "Enter position to delete: "; cin >> position;
                library.deleteBookByPosition(position);
                break;

            case 5:
                cout << "\n--- Library Books ---\n";
                library.displayFromStart();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

