#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the kth largest element in the array
int kthLargest(vector<int> arr, int k)
{
    // Step 1: Create a min-heap using priority_queue
    // The priority_queue is initialized to store the smallest element at the top
    priority_queue<int, vector<int>, greater<int>> p;

    // Step 2: Add the first 'k' elements to the min-heap
    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }

    // Step 3: Process the remaining elements in the array
    for (int i = k; i < arr.size(); i++)
      {
        // If the current element is greater than the smallest element in the hea
        if (arr[i] > p.top())
        {
            p.pop();        
            p.push(arr[i]);
        }
    }

    return p.top();
}

int main()
{
    // Input array
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    // Value of k
    int k = 2;

    // Output the kth largest element
    cout << k << "th largest element: " << kthLargest(arr, k) << endl;

    return 0;
}
