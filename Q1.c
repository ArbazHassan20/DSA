#include <iostream>
using namespace std;

int main()
{
    int **matrix = new int*[3]; // Pointer to array of pointers
    int rowSizes[3]; // Array to store sizes of each row
    int i, j;

    // Input row sizes and allocate memory
    for (i = 0; i < 3; i++) {
        cout << "Enter size for row " << i + 1 << ": ";
        cin >> rowSizes[i];
        if (rowSizes[i] != 10) rowSizes[i] = 10; // Set row size to 10 if not specified
        matrix[i] = new int[rowSizes[i]];
    }

    // Input elements into the matrix
    for (i = 0; i < 3; i++) {
        for (j = 0; j < rowSizes[i]; j++) {
            cout << "Enter element for row " << i + 1 << ", column " << j << ": ";
            cin >> matrix[i][j];
        }
    }

    // Display matrix elements
    for (i = 0; i < 3; i++) {
        for (j = 0; j < rowSizes[i]; j++) {
            cout << "Element at [" << i << "][" << j << "]: " << matrix[i][j] << endl;
        }
    }

    // Deallocate memory
    for (i = 0; i < 3; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
