#include <iostream>
using namespace std;

// Function to create and initialize a grid
bool** createGrid() {
    bool** grid = new bool*[5];
    for (size_t i = 0; i < 5; i++) {
        grid[i] = new bool[5]{false}; // Initialize all elements to false
    }
    
    // Set true values representing friendships
    grid[0][1] = true; grid[0][3] = true;
    grid[0][4] = true; grid[1][0] = true; grid[1][2] = true;
    grid[1][4] = true;
    grid[2][1] = true; grid[3][0] = true;
    grid[3][4] = true; grid[4][0] = true; grid[4][1] = true;
    grid[4][3] = true;

    return grid;
}

// Function to print the grid
void printGrid(bool** grid) {
    cout << "   ";
    for (size_t j = 0; j < 5; j++) {
        cout << j << "   ";
    }
    cout << endl;

    for (size_t i = 0; i < 5; i++) {
        cout << i << " ";
        for (size_t j = 0; j < 5; j++) {
            cout << "[" << grid[i][j] << "] ";
        }
        cout << endl;
    }
}

// Function to check if two persons have a mutual friend
void checkMutualFriends(bool** grid, int person1, int person2) {
    bool found = false;
    int mutualFriend = -1;
    for (size_t i = 0; i < 5; i++) {
        if (grid[person1][i] && grid[person2][i]) {
            found = true;
            mutualFriend = i;
        }
    }
    if (found) 
        cout << person1 << " & " << person2 << " are friends with " << mutualFriend << endl;
    else 
        cout << "No mutual friend found" << endl;
}

// Main function
int main() {
    bool** grid = createGrid();
    printGrid(grid);
    checkMutualFriends(grid, 0, 2); // Checking if 0 & 2 have a common friend

    // Deallocate memory
    for (size_t i = 0; i < 5; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}

