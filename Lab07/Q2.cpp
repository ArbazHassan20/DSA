#include <iostream>
using namespace std;

class Runner
{
    string name;
    float time;

public:
    Runner()
    {
        name = "";
        time = 0;
    }
    Runner(string n, float t)
    {
        name = n;
        time = t;
    }
    string get_name()
    {
        return name;
    }
    float get_time()
    {
        return time;
    }
};

void merge(Runner arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    Runner *temp = new Runner[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (arr[i].get_time() >= arr[j].get_time())
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int count = 0; count < k; count++)
    {
        arr[low + count] = temp[count];
    }

    delete[] temp;
}

void mergeSort(Runner arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main()
{
    Runner *runners = new Runner[10];
    string name;
    float time;

    for (int i = 0; i < 10; i++)
    {
        cout << "Please enter the name of runner " << i + 1 << ": ";
        cin >> name;
        cout << "Please enter the finish time of " << name << " (in seconds): ";
        cin >> time;
        runners[i] = Runner(name, time);
    }

    mergeSort(runners, 0, 9);

    cout << "\nThe top 5 fastest runners are: \n";
    for (int i = 4; i < 10; i++)
    {
        cout << i + 1 << ". " << runners[i].get_name() << " - " << runners[i].get_time() << " seconds\n";
    }

    delete[] runners;
}
