#include <iostream>
#include <string>
using namespace std;

#define MAX 100 // Maximum capacity of the queue

class TicketQueue {
private:
    string tickets[MAX]; // Array to store tickets
    int front, rear;     // Front and rear pointers

public:
    // Constructor: Initialize an empty queue
    TicketQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == MAX - 1;
    }

    // Add a customer ticket (enqueue)
    void enqueue(string ticket) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more tickets.\n";
            return;
        }

        if (isEmpty()) front = 0; // If first ticket is added, set front to 0
        tickets[++rear] = ticket;
        cout << "Ticket \"" << ticket << "\" added to the queue.\n";
    }

    // Process the next customer ticket (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No tickets to process.\n";
            return;
        }

        cout << "Processing ticket: \"" << tickets[front] << "\"\n";
        front++;

        // Reset pointers if queue becomes empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // Display all pending tickets
    void display() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
            return;
        }

        cout << "Pending tickets (Front to Rear):\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << tickets[i] << "\n";
        }
    }

    // Cancel a specific customer ticket
    void cancelTicket(string ticket) {
        if (isEmpty()) {
            cout << "Queue is empty! No tickets to cancel.\n";
            return;
        }

        int pos = -1;
        for (int i = front; i <= rear; i++) {
            if (tickets[i] == ticket) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Ticket \"" << ticket << "\" not found.\n";
            return;
        }

        cout << "Ticket \"" << ticket << "\" cancelled.\n";

        // Shift tickets to fill the gap
        for (int i = pos; i < rear; i++) {
            tickets[i] = tickets[i + 1];
        }
        rear--;

        // Reset queue if empty after cancellation
        if (rear < front) {
            front = -1;
            rear = -1;
        }
    }
};

int main() {
    TicketQueue queue;
    int choice;
    string ticket;

    do {
        cout << "\n--- Customer Service Ticketing System ---\n";
        cout << "1. Add Ticket (Enqueue)\n";
        cout << "2. Process Ticket (Dequeue)\n";
        cout << "3. Display All Tickets\n";
        cout << "4. Check if Queue is Empty or Full\n";
        cout << "5. Cancel a Ticket\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter ticket description: ";
                getline(cin, ticket);
                queue.enqueue(ticket);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << (queue.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                cout << (queue.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 5:
                cout << "Enter ticket description to cancel: ";
                getline(cin, ticket);
                queue.cancelTicket(ticket);
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
