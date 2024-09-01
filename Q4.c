#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to initialize a jagged array with random GPA values
float** initCourses() {
    const int numCourses = 4;
    float** arr = new float*[numCourses];
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    for (int i = 0; i < numCourses; i++) {
        arr[i] = new float[numCourses - i];
        for (int j = 0; j < numCourses - i; j++) {
            arr[i][j] = static_cast<float>(rand() % 4 + 1); // Random GPA between 1 and 4
        }
    }
    return arr;
}

// Function to print the jagged array with course names
void printCourses(float** arr, int numCourses) {
    const char* courseNames[] = {"AI Core Course GPAs:", "SE Core Course GPAs:", 
                                  "CS Core Course GPAs:", "DS Core Course GPAs:"};

    for (int i = 0; i < numCourses; i++) {
        cout << courseNames[i] << " ";
        for (int j = 0; j < numCourses - i; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    const int numCourses = 4;
    float** jaggedArr = initCourses();
    printCourses(jaggedArr, numCourses);

    // Deallocate memory
    for (int i = 0; i < numCourses; i++) {
        delete[] jaggedArr[i];
    }
    delete[] jaggedArr;

    return 0;
}
