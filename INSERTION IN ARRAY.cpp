#include <iostream>
using namespace std;

// Function to display the array
void displayArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to insert an element at a specific position
void insertElement(int arr[], int &size, int element, int position) {
    if (position < 0 || position > size) {
        cout << "Invalid position! Insertion failed.\n";
        return;
    }

    // Shift elements to the right to create space
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element; // Insert element
    size++;
    cout << "Element inserted successfully.\n";
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int &size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position! Deletion failed.\n";
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--; // Reduce the array size
    cout << "Element deleted successfully.\n";
}

int main() {
    int size, choice, element, position;

    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[100]; // Maximum capacity of 100 elements

    cout << "Enter " << size << " array elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete an element\n";
        cout << "3. Display array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> element;
                cout << "Enter the position to insert (0-based index): ";
                cin >> position;
                insertElement(arr, size, element, position);
                break;

            case 2:
                cout << "Enter the position to delete (0-based index): ";
                cin >> position;
                deleteElement(arr, size, position);
                break;

            case 3:
                displayArray(arr, size);
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
