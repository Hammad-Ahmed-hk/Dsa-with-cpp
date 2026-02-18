#include <iostream>
#include <vector>
using namespace std;

// Function to perform Binary Search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevents overflow

        if (arr[mid] == target) return mid;      // Target found
        else if (arr[mid] < target) left = mid + 1;  // Search right half
        else right = mid - 1;                        // Search left half
    }

    return -1;  // Target not found
}

// Function to perform Ternary Search
int ternarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;      // First mid-point
        int mid2 = right - (right - left) / 3;     // Second mid-point

        if (arr[mid1] == target) return mid1;      // Target found at mid1
        if (arr[mid2] == target) return mid2;      // Target found at mid2

        if (target < arr[mid1]) right = mid1 - 1;        // Search in left segment
        else if (target > arr[mid2]) left = mid2 + 1;    // Search in right segment
        else {                                           // Search in middle segment
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return -1;  // Target not found
}

// Function to display the array
void displayArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n, target;

    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the sorted array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> target;

    cout << "\nArray: ";
    displayArray(arr);

    int binaryResult = binarySearch(arr, target);
    int ternaryResult = ternarySearch(arr, target);

    cout << "\n?? Search Results:\n";
    if (binaryResult != -1)
        cout << "? Binary Search: Element " << target << " found at index " << binaryResult << ".\n";
    else
        cout << "? Binary Search: Element " << target << " not found.\n";

    if (ternaryResult != -1)
        cout << "? Ternary Search: Element " << target << " found at index " << ternaryResult << ".\n";
    else
        cout << "? Ternary Search: Element " << target << " not found.\n";

    return 0;
}
