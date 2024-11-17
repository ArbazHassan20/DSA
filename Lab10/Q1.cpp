#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the maximum element in every sliding window of size 'k'
vector<int> maxSW(vector<int> &nums, int k)
{
    vector<int> ans;
  
   // A max-heap (priority queue) to store elements of the current window
    priority_queue<int> p;

    // Add the first 'k' elements to the priority queue
    for (int i = 0; i < k; i++)
    {
        p.push(nums[i]);
    }
    ans.push_back(p.top());

    for (int i = k; i < nums.size(); i++)
    {
        p.push(nums[i]);

        while (!p.empty() && p.top() == nums[i - k])
        {
            p.pop();
        }
      
        ans.push_back(p.top());
    }

    return ans;
}

int main()
{
    // Input vector
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7, 12, 22, -5, 8};

    // Size of the sliding window
    int k = 3;

    // Call the function to get the result
    vector<int> max = maxSW(nums, k);

    // Print the result
    for (int i = 0; i < max.size(); i++) // Corrected 'int i;' to 'int i = 0;'
    {
        cout << max[i] << " ";
    }

    return 0;
}
