#include <iostream>
using namespace std;

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int n, int target) {
    if (n == 0) {  // Handle empty array
        return -1;
    }

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Target found, return index
        } else if (arr[mid] < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }

    return -1;  // Target not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    if (n == 0) {
        cout << "Error: Input array is empty." <<endl;
        return 1;
    }

    int index = binarySearch(arr, n, target);

    if (index != -1) {
     cout << "Element found at index: " << index <<endl;
    } else {
        cout << "Element not found." <<endl;
    }

    return 0;
}