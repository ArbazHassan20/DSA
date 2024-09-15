#include <iostream>
using namespace std;
#define arr_size 5

void bubble_sort(int* data)
{
    for(int i = 0; i < arr_size; i++)
    {
        for(int j = 0; j < arr_size - i - 1; j++)
        {
            if(data[j] > data[j+1])
            {
                int swap_temp = data[j];
                data[j] = data[j+1];
                data[j+1] = swap_temp;
            }
        }
    }
}

void shell_sort(int* data)
{
    for (int gap = arr_size/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < arr_size; i++)
        {
            int temp_value = data[i];
            int j;            
            for (j = i; j >= gap && data[j - gap] > temp_value; j -= gap)
                data[j] = data[j - gap];
            data[j] = temp_value;
        }
    }
}

void selection_sort(int* data)
{
    for(int i = 0; i < arr_size - 1; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < arr_size; j++)
        {
            if(data[j] < data[min_index])
            {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            int swap_temp = data[min_index];
            data[min_index] = data[i];
            data[i] = swap_temp;
        }
    }
}

void insertion_sort(int* data)
{
    for(int i = 1; i < arr_size; i++)
    {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

void comb_sort(int *data) 
{
    int gap = arr_size;
    bool sorted = true;

    while(gap != 1 || sorted == true) 
    {
        gap = (gap*10)/13; 
        if(gap < 1)
            gap = 1;

        sorted = false;
        for(int i = 0; i < arr_size - gap; i++) 
        { 
            if(data[i] > data[i + gap]) 
            {
                int swap_temp = data[i + gap];
                data[i + gap] = data[i];
                data[i] = swap_temp;
                sorted = true;
            }
        }
    }
}

void print_array(int* data)
{
    for(int i = 0; i < arr_size; i++) 
        cout << data[i] << " ";
    cout << "\n";
}

int linear_search(int* data, int target)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (data[i] == target)
            return i;
    }
    return -1;
}
 
int main()
{
    int arr1[] = {10, 34, 23, 78, 56};
    cout << "Before bubble sort:\n";
    print_array(arr1);
    bubble_sort(arr1);
    cout << "After bubble sort:\n";
    print_array(arr1);

    int arr2[] = {45, 67, 12, 89, 34};
    cout << "\nBefore selection sort:\n";
    print_array(arr2);
    selection_sort(arr2);
    cout << "After selection sort:\n";
    print_array(arr2);

    int arr3[] = {9, 17, 43, 21, 87};
    cout << "\nBefore insertion sort:\n";
    print_array(arr3);
    insertion_sort(arr3);
    cout << "After insertion sort:\n";
    print_array(arr3);

    int arr4[] = {20, 15, 30, 5, 40};
    cout << "\nBefore shell sort:\n";
    print_array(arr4);
    shell_sort(arr4);
    cout << "After shell sort:\n";
    print_array(arr4);

    int arr5[] = {44, 13, 77, 55, 99};
    cout << "\nBefore comb sort:\n";
    print_array(arr5);
    comb_sort(arr5);
    cout << "After comb sort:\n";
    print_array(arr5);

    int search_result = linear_search(arr5, 77);
    (search_result == -1) ? 
    cout << "Element not found in the array\n" : 
    cout << "Element found at index " << search_result << "\n";
    
    return 0;
}
