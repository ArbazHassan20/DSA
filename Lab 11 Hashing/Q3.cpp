#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table; 
    int size;          
    int count;          
    const int EMPTY = -1; 
    const int DELETED = -2;
    const double LOAD_FACTOR_THRESHOLD = 0.75;

    // Hash function to calculate index
    int hashFunction(int key) {
        return key % size;
    }

    // Resize the hash table when load factor exceeds the threshold
    void resize() {
        int newSize = size * 2; // Double the size
        vector<int> newTable(newSize, EMPTY); // New hash table
        size = newSize;
        count = 0;

        // Rehash all existing elements into the new table
        for (int i = 0; i < table.size(); ++i) {
            if (table[i] != EMPTY && table[i] != DELETED) {
                insertIntoNewTable(newTable, table[i]);
            }
        }

        table = newTable; // Update the table reference
        cout << "Table resized to new size: " << size << endl;
    }

    // Helper function to insert into the new table during resizing
    void insertIntoNewTable(vector<int>& newTable, int key) {
        int index = key % size;
        while (newTable[index] != EMPTY) {
            index = (index + 1) % size;
        }
        newTable[index] = key;
        count++;
    }

public:
    HashTable(int initialSize) : size(initialSize), count(0) {
        table.resize(size, EMPTY);
    }

    void insert(int key) {
        if ((double)count / size >= LOAD_FACTOR_THRESHOLD) {
            resize();
        }

        int index = hashFunction(key);
        while (table[index] != EMPTY && table[index] != DELETED) {
            index = (index + 1) % size;
        }
        table[index] = key;
        count++;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int start = index; // Remember the starting position for full loop detection

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                cout << "Student ID " << key << " found at index " << index << endl;
                return true;
            }
            index = (index + 1) % size;
            if (index == start) break; // Full loop detection
        }
        cout << "Student ID " << key << " not found." << endl;
        return false;
    }

    void display() {
        cout << "Hash Table (Size: " << size << "):" << endl;
        for (int i = 0; i < size; ++i) {
            if (table[i] == EMPTY)
                cout << "Index " << i << ": EMPTY" << endl;
            else if (table[i] == DELETED)
                cout << "Index " << i << ": DELETED" << endl;
            else
                cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable university(7);

    int studentIDs[] = {12, 22, 32, 42, 52, 62};
    for (int id : studentIDs) {
        university.insert(id);
    }

    cout << "\nAfter inserting student IDs 12, 22, 32, 42, 52, 62:" << endl;
    university.display();

    // Search for student IDs: 22, 42, 72
    cout << "\nSearching for student IDs:" << endl;
    university.search(22);
    university.search(42);
    university.search(72);

    cout << "\nInserting student IDs 72 and 82:" << endl;
    university.insert(72);
    university.insert(82);

    cout << "\nAfter inserting additional IDs:" << endl;
    university.display();

    return 0;
}
