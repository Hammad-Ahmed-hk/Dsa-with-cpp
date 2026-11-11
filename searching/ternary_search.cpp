#include <iostream>
#include <string>
#define MAX 5  // Maximum number of books in the stack
using namespace std;

class BookStack {
private:
    int top;
    string books[MAX];  // Array to store books

public:
    BookStack() {
        top = -1;  // Stack is initially empty
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Check if the stack is full
    bool isFull() {
        return (top == MAX - 1);
    }

    // Push a book onto the stack
    void push(string bookName) {
        if (isFull()) {
            cout << "Stack is full! Cannot add more books.\n";
            return;
        }
        top++;
        books[top] = bookName;
        cout << "Book \"" << bookName << "\" added to the stack.\n";
    }

    // Pop a book from the stack (Remove the top book)
    void pop() {
        if (isEmpty()) {
            cout << "No books to remove. Stack is empty!\n";
            return;
        }
        cout << "Book \"" << books[top] << "\" removed from the stack.\n";
        top--;
    }

    // Peek at the top book (View last added book)
    void peek() {
        if (isEmpty()) {
            cout << "No books to show. Stack is empty!\n";
            return;
        }
        cout << "Top book: \"" << books[top] << "\"\n";
    }

    // Display all books in stack order (Top to Bottom)
    void display() {
        if (isEmpty()) {
            cout << "No books in the stack.\n";
            return;
        }
        cout << "Books in stack (Top to Bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << books[i] << endl;
        }
    }
};

int main() {
    BookStack stack;
    int choice;
    string bookName;

    do {
        cout << "\nLibrary Book Stack System\n";
        cout << "1. Add a Book (Push)\n";
        cout << "2. Remove a Book (Pop)\n";
        cout << "3. View Top Book (Peek)\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter book name: ";
                getline(cin, bookName);
                stack.push(bookName);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}