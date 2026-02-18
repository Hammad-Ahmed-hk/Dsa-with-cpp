#include <iostream>
#include <vector>

using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<double>& prices, bool ascending) {
    int n = prices.size();
    for (int i = 0; i < n - 1; i++) {
        int selectedIndex = i;

        // Find the minimum or maximum element based on the sorting order
        for (int j = i + 1; j < n; j++) {
            if (ascending) {
                if (prices[j] < prices[selectedIndex]) {
                    selectedIndex = j;
                }
            } else {
                if (prices[j] > prices[selectedIndex]) {
                    selectedIndex = j;
                }
            }
        }

        // Swap the selected element with the current element
        swap(prices[i], prices[selectedIndex]);
    }
}

int main() {
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Sort prices in ascending order\n";
        cout << "2. Sort prices in descending order\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting program. Goodbye!\n";
            break;
        }

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice! Please try again.\n";
            continue;
        }

        // Determine sorting order
        bool ascending = (choice == 1);

        int n;
        cout << "Enter the number of product prices: ";
        cin >> n;

        vector<double> prices(n);
        cout << "Enter the product prices:\n";
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }

        // Sort the prices
        selectionSort(prices, ascending);

        // Display the sorted prices
        cout << "\nSorted product prices:\n";
        for (double price : prices) {
            cout << price << " ";
        }
        cout << endl;
    }

    return 0;
}
