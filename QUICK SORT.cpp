#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Partition function that uses the first element as the pivot
template <typename T>
int partition(vector<T>& arr, int low, int high) {
    T pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

// Quick Sort function to sort an array
template <typename T>
void quickSort(vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);        // Recursively sort left part
        quickSort(arr, pi + 1, high);       // Recursively sort right part
    }
}

int main() {
    int n;
    cout << "Enter the number of delivery routes: ";
    cin >> n;

    // Input array of delivery durations
    vector<int> durations(n);
    cout << "Enter the delivery durations (in hours):\n";
    for (int i = 0; i < n; i++) {
        cin >> durations[i];
    }

    // Sorting the delivery durations using Quick Sort
    quickSort(durations, 0, n - 1);

    // Output the sorted durations
    cout << "\nSorted delivery durations (in hours):\n";
    for (int i = 0; i < n; i++) {
        cout << durations[i] << " ";
    }
    cout << endl;

    // Input array of delivery route names
    vector<string> routes(n);
    cout << "Enter the names of the delivery routes:\n";
    cin.ignore(); // To ignore the newline character left by previous input
    for (int i = 0; i < n; i++) {
        getline(cin, routes[i]);
    }

    // Sorting the delivery route names using Quick Sort
    quickSort(routes, 0, n - 1);

    // Output the sorted routes
    cout << "\nSorted delivery routes (alphabetically):\n";
    for (int i = 0; i < n; i++) {
        cout << routes[i] << endl;
    }

    return 0;
}
