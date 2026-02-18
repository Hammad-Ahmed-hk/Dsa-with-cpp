#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort for Array
void bubbleSortArray(vector<int>& salaries) {
    int n = salaries.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                swap(salaries[j], salaries[j + 1]); // Swap elements
            }
        }
    }
}

// Display Array
void displayArray(const vector<int>& salaries) {
    for (int salary : salaries) {
        cout << salary << " ";
    }
    cout << endl;
}

// Node structure for Linked List
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Linked List Implementation
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Append a new node
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Bubble Sort for Linked List
    void bubbleSort() {
        if (!head) return;

        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr; // Pointer to track the last sorted node

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    swap(ptr1->data, ptr1->next->data); // Swap data values
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    // Display Linked List
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Permanent Employee Salaries (Array)
    vector<int> permanentSalaries = {50000, 30000, 45000, 60000, 55000, 70000, 40000, 65000, 35000, 25000};

    cout << "Original Permanent Salaries (Array): ";
    displayArray(permanentSalaries);

    bubbleSortArray(permanentSalaries);

    cout << "Sorted Permanent Salaries (Array): ";
    displayArray(permanentSalaries);

    // Contract Employee Salaries (Linked List)
    LinkedList contractSalaries;
    contractSalaries.append(45000);
    contractSalaries.append(35000);
    contractSalaries.append(25000);
    contractSalaries.append(55000);
    contractSalaries.append(40000);
    contractSalaries.append(30000);
    contractSalaries.append(70000);
    contractSalaries.append(60000);
    contractSalaries.append(50000);
    contractSalaries.append(65000);

    cout << "\nOriginal Contract Salaries (Linked List): ";
    contractSalaries.display();

    contractSalaries.bubbleSort();

    cout << "Sorted Contract Salaries (Linked List): ";
    contractSalaries.display();

    return 0;
}
