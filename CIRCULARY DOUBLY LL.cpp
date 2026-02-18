#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class CircularDoublyLinkedList {
private:
    Node* tail; // Only one pointer to manage the list

public:
    CircularDoublyLinkedList() : tail(nullptr) {}

    // Insert at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (!tail) { // List is empty
            tail = newNode;
            tail->next = tail;
            tail->prev = tail;
        } else {
            Node* head = tail->next;
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (!tail) { // List is empty
            tail = newNode;
            tail->next = tail;
            tail->prev = tail;
        } else {
            Node* head = tail->next;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode; // Update tail
        }
    }

    // Insert at a specific position (1-based index)
    void insertAtPosition(int data, int position) {
        if (position < 1) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node{data, nullptr, nullptr};
        if (position == 1) {
            insertAtBeginning(data);
            return;
        }

        Node* temp = tail->next; // Start from head
        int index = 1;
        while (temp != tail && index < position - 1) {
            temp = temp->next;
            index++;
        }

        if (temp == tail && index < position - 1) {
            cout << "Position out of range\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != tail->next) {
            temp->next->prev = newNode;
        } else {
            tail = newNode; // Update tail if inserting at the end
        }
        temp->next = newNode;
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
            Node* head = tail->next;
            tail->next = head->next;
            head->next->prev = tail;
            delete head;
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
            Node* head = tail->next;
            Node* prev = tail->prev;
            prev->next = head;
            head->prev = prev;
            delete tail;
            tail = prev; // Update tail
        }
    }

    // Delete from a specific position (1-based index)
    void deleteFromPosition(int position) {
        if (!tail || position < 1) { // List is empty or invalid position
            cout << "Invalid position or List is empty\n";
            return;
        }

        Node* temp = tail->next; // Start from head
        int index = 1;
        while (temp != tail && index < position) {
            temp = temp->next;
            index++;
        }

        if (temp == tail && index < position) {
            cout << "Position out of range\n";
            return;
        }

        if (temp == tail && temp->next == tail) { // Only one node
            delete tail;
            tail = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == tail) {
                tail = temp->prev; // Update tail if deleting the last node
            }
            delete temp;
        }
    }

    // Traverse forward
    void traverseForward() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail->next; // Start from head
        cout << "List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "HEAD\n";
    }

    // Traverse backward
    void traverseBackward() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail; // Start from tail
        cout << "List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->prev;
        } while (temp != tail);
        cout << "TAIL\n";
    }
};

int main() {
    CircularDoublyLinkedList cdll;
    int num, position;

    // Get 5 numbers from the user and insert at the end
    cout << "Enter 5 numbers to add to the list:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> num;
        cdll.insertAtEnd(num);
    }

    // Display the list before any changes
    cout << "Before any changes:\n";
    cdll.traverseForward();

    // Perform some changes (deleting from beginning, end, and specific position)
    cout << "\nEnter a position to insert a number (1-based): ";
    cin >> position;
    cout << "Enter the number to insert at position " << position << ": ";
    cin >> num;
    cdll.insertAtPosition(num, position);
    cdll.traverseForward();

    cout << "\nEnter a position to delete from (1-based): ";
    cin >> position;
    cdll.deleteFromPosition(position);
    cdll.traverseForward();

    // Deleting from beginning and end
    cdll.deleteFromBeginning();
    cdll.deleteFromEnd();

    // Final list display
    cout << "After changes (deleting from beginning, end, and position):\n";
    cdll.traverseForward();

    return 0;
}
