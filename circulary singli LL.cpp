#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularSinglyLinkedList {
private:
    Node* tail; // Only one pointer to manage the entire list

public:
    CircularSinglyLinkedList() : tail(nullptr) {}

    // Insert at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node{data, nullptr};
        if (!tail) { // List is empty
            tail = newNode;
            tail->next = tail; // Circular connection
        } else {
            newNode->next = tail->next; // Point to head
            tail->next = newNode;       // Update tail’s next to new head
        }
    }

    // Insert at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr};
        if (!tail) { // List is empty
            tail = newNode;
            tail->next = tail; // Circular connection
        } else {
            newNode->next = tail->next; // Point to head
            tail->next = newNode;       // Link current tail to new node
            tail = newNode;             // Update tail to new node
        }
    }

    // Insert at a specific position
    void insertAtPosition(int data, int position) {
        Node* newNode = new Node{data, nullptr};
        if (!tail) { // List is empty
            if (position == 1) {
                tail = newNode;
                tail->next = tail; // Circular connection
            } else {
                cout << "Invalid position! The list is empty.\n";
                delete newNode;
            }
            return;
        }
        if (position == 1) { // Insert at the beginning
            insertAtBeginning(data);
            return;
        }
        Node* temp = tail->next; // Start from head
        int currentPos = 1;
        while (currentPos < position - 1 && temp != tail) {
            temp = temp->next;
            currentPos++;
        }
        if (currentPos == position - 1) {
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == tail) { // If inserting at the end
                tail = newNode;
            }
        } else {
            cout << "Invalid position!\n";
            delete newNode;
        }
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (!tail) { // List is empty
            cout << "List is empty\n";
            return;
        }
        if (tail->next == tail) { // Single node
            delete tail;
            tail = nullptr;
        } else {
            Node* temp = tail->next; // Head node
            tail->next = temp->next; // Update tail’s next to new head
            delete temp;
        }
    }

    // Delete from the end
    void deleteFromEnd() {
        if (!tail) { // List is empty
            cout << "List is empty\n";
            return;
        }
        if (tail->next == tail) { // Single node
            delete tail;
            tail = nullptr;
        } else {
            Node* temp = tail->next; // Start from head
            while (temp->next != tail) // Find the second last node
                temp = temp->next;
            temp->next = tail->next; // Update second last node’s next to head
            delete tail;
            tail = temp; // Update tail to second last node
        }
    }

    // Delete from a specific position
    void deleteFromPosition(int position) {
        if (!tail) { // List is empty
            cout << "List is empty\n";
            return;
        }
        if (position == 1) { // Delete the first node
            deleteFromBeginning();
            return;
        }
        Node* temp = tail->next; // Start from head
        int currentPos = 1;
        while (currentPos < position - 1 && temp->next != tail->next) {
            temp = temp->next;
            currentPos++;
        }
        if (currentPos == position - 1 && temp->next != tail->next) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete == tail) { // If deleting the last node
                tail = temp;
            }
            delete toDelete;
        } else {
            cout << "Invalid position!\n";
        }
    }

    // Traverse the list
    void traverse(const string& heading) {
        cout << heading << endl;
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail->next; // Start from head
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "HEAD\n";
    }
};

int main() {
    CircularSinglyLinkedList csll;
    int number, position;

    cout << "Enter 5 numbers to insert into the list:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> number;
      csll.insertAtEnd(number); // Insert each number at the end
  
    }
    
    // Display the list before any changes
    csll.traverse("Before any changes:");

    // Insert at a specific position
    cout << "Enter a number to insert at a specific position: ";
    cin >> number;
    cout << "Enter the position to insert: ";
    cin >> position;
    csll.insertAtPosition(number, position);
    csll.traverse("After inserting at a specific position:");

    // Delete from the beginning
    csll.deleteFromBeginning();
    csll.traverse("After deleting from the beginning:");

    // Delete from the end
    csll.deleteFromEnd();
    csll.traverse("After deleting from the end:");

    // Delete from a specific position
    cout << "Enter the position to delete: ";
    cin >> position;
    csll.deleteFromPosition(position);
    csll.traverse("After deleting from a specific position:");

    return 0;
}
