#include <iostream>
#include <vector>
using namespace std;

int getdigit(int number, int place) {
    return (number / place) % 10;
}

int getmax(const vector<int>& arr) {
    int maxelement = arr[0];
    for (int num : arr) {
        if (num > maxelement) {
            maxelement = num;
        }
    }
    return maxelement;
}

void radixsortascending(vector<int>& arr) {
    int base = 10;  
    int maxelement = getmax(arr); 

    for (int place = 1; maxelement / place > 0; place *= 10) {
        vector<int> count(base, 0);  
        vector<int> output(arr.size());  

        for (int num : arr) {
            int digit = getdigit(num, place);
            count[digit]++;
        }
        for (int i = 1; i < base; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            int digit = getdigit(arr[i], place);
            output[--count[digit]] = arr[i];
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
    }
}

void reversearray(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}
void radixsortdescending(vector<int>& arr) {
    radixsortascending(arr);  
    reversearray(arr); 
}

void display(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original Array:";
    display(arr);

    radixsortascending(arr);
    cout << "Sorted Array in Ascending Order:";
    display(arr);

    radixsortdescending(arr);
    cout << "Sorted Array in Descending Order:";
    display(arr);

    return 0;
}
