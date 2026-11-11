#include <iostream>
#include <string>
using namespace std;

#define MAX 100 // Maximum capacity of the stack

class BookStack {
private:
    string books[MAX]; // Array to store books
    int top;           // Index of the top element

public:
    // Constructor to initialize the stack
    BookStack() {
        top = -1; // Stack is initially empty
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Push a book onto the stack
    void push(string bookName) {
        if (isFull()) {
            cout << "Stack is full! Cannot add more books.\n";
            return;
        }
        books[++top] = bookName;
        cout << "Book \"" << bookName << "\" added to the stack.\n";
    }

    // Pop a book from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! No books to remove.\n";
            return;
        }
        cout << "Book \"" << books[top--] << "\" removed from the stack.\n";
    }

    // Peek at the top book
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top book.\n";
            return;
        }
        cout << "Top book: \"" << books[top] << "\"\n";
    }

    // Display all books in the stack from top to bottom
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty! No books to display.\n";
            return;
        }
        cout << "Books in the stack (Top to Bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << i + 1 << ". " << books[i] << "\n";
        }
    }
};

int main() {
    BookStack stack;
    int choice;
    string bookName;

    do {
        cout << " Book Management System (Stack) ";
        cout << "1. Add a Book (Push)\n";
        cout << "2. Remove Top Book (Pop)\n";
        cout << "3. View Top Book (Peek)\n";
        cout << "4. Display All Books\n";
        cout << "5. Check if Stack is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book name: ";
                getline(cin, bookName); // Read book name with spaces
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
                cout << (stack.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
                break;
            case 6:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
