#include <iostream>
#include <cstdlib>
#include <ctime>
#define ROW 3

using namespace std;

// Array of names to be used in the seating chart
const string names[ROW][4] = {
    {"Alice", "Bob", "Charlie", "David"},
    {"Eve", "Frank", "Grace", "Hank"},
    {"Ivy", "Chase", "Peter", "Catherine"}
};

// Function to initialize the seating chart with names and random seat counts
string** initSeats(int* seatCounts) {
    string** seatingChart = new string*[ROW];
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    for (int i = 0; i < ROW; i++) {
        int seatsInRow = rand() % 4 + 1; // Random number of seats between 1 and 4
        seatingChart[i] = new string[seatsInRow];
        seatCounts[i] = seatsInRow;
        
        for (int j = 0; j < seatsInRow; j++) {
            seatingChart[i][j] = names[i][j];
        }
    }
    return seatingChart;
}

// Function to print the seating chart
void printSeatingChart(string** seatingChart, int* seatCounts) {
    for (int i = 0; i < ROW; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < seatCounts[i]; j++) {
            cout << seatingChart[i][j] << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    int seatCounts[ROW];
    string** seats = initSeats(seatCounts);
    printSeatingChart(seats, seatCounts);

    // Deallocate memory
    for (int i = 0; i < ROW; i++) {
        delete[] seats[i];
    }
    delete[] seats;

    return 0;
}
