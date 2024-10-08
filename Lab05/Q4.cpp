#include <iostream>
using namespace std;

int binarySearch(const int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 
        
        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return -1;
}

int main() {
    const int size = 10;
    int sortedArray[size] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;

    int result = binarySearch(sortedArray, size, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
