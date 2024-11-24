#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table; // Hash table
    int size;          // Size of the hash table
    const int EMPTY = -1; // Marker for empty slot
    const int DELETED = -2; // Marker for deleted slot

    // Hash function to calculate index
    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int size) : size(size) {
        table.resize(size, EMPTY);
    }

    void insert(int key) {
        int index = hashFunction(key);
        int start = index;
        while (table[index] != EMPTY && table[index] != DELETED) {
            index = (index + 1) % size;
            if (index == start) {
                cout << "Hash table is full. Cannot insert " << key << endl;
                return;
            }
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int start = index; // Remember the starting position for full loop detection

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                cout << "Member ID " << key << " found at index " << index << endl;
                return true;
            }
            index = (index + 1) % size;
            if (index == start) break; // Full loop detection
        }
        cout << "Member ID " << key << " not found." << endl;
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int start = index; // Remember the starting position for full loop detection

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                cout << "Deleting Member ID " << key << " from index " << index << endl;
                table[index] = DELETED;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break; // Full loop detection
        }
        cout << "Member ID " << key << " not found for deletion." << endl;
    }

    void display() {
        cout << "Hash Table:" << endl;
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
    HashTable club(7);

    int memberIDs[] = {10, 20, 30, 40, 50, 60};
    for (int id : memberIDs) {
        club.insert(id);
    }

    cout << "\nAfter inserting member IDs 10 - 60:" << endl;
    club.display();

    cout << "\nSearching for member IDs:" << endl;
    club.search(30);
    club.search(50);
    club.search(70);
    cout << "\nDeleting member IDs 20 and 40:" << endl;
    club.remove(20);
    club.remove(40);

    cout << "\nAfter deletions:" << endl;
    club.display();

    cout << "\nInserting member IDs 70 and 80:" << endl;
    club.insert(70);
    club.insert(80);

    cout << "\nAfter inserting additional member IDs:" << endl;
    club.display();

    return 0;
}
