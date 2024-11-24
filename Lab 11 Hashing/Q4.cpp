#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;  
    int size;           
    const int EMPTY = -1;
    const int DELETED = -2; 

   
    int primaryHash(int key) {
        return key % size;
    }
    int secondaryHash(int key) {
        return 7 - (key % 7);
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size, EMPTY);
    }
    void insert(int key) {
        int index = primaryHash(key);
        int step = secondaryHash(key);
        int start = index; 
        while (table[index] != EMPTY && table[index] != DELETED) {
            index = (index + step) % size;
            if (index == start) { 
                cout << "Hash table is full. Cannot insert " << key << endl;
                return;
            }
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = primaryHash(key);
        int step = secondaryHash(key);
        int start = index;
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                cout << "Account number " << key << " found at index " << index << endl;
                return true;
            }
            index = (index + step) % size;
            if (index == start) break; // Full loop detection
        }
        cout << "Account number " << key << " not found." << endl;
        return false;
    }

    void remove(int key) {
        int index = primaryHash(key);
        int step = secondaryHash(key);
        int start = index; 
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                cout << "Deleting account number " << key << " from index " << index << endl;
                table[index] = DELETED;
                return;
            }
            index = (index + step) % size;
            if (index == start) break; // Full loop detection
        }
        cout << "Account number " << key << " not found for deletion." << endl;
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
    HashTable bankingSystem(11);

    int accountNumbers[] = {101, 111, 121, 131, 141, 151};
    for (int acc : accountNumbers) {
        bankingSystem.insert(acc);
    }

    cout << "\nAfter inserting account numbers 101, 111, 121, 131, 141, 151:" << endl;
    bankingSystem.display();

    cout << "\nSearching for account numbers:" << endl;
    bankingSystem.search(111);
    bankingSystem.search(141);
    bankingSystem.search(161);

    cout << "\nDeleting account numbers 111 and 131:" << endl;
    bankingSystem.remove(111);
    bankingSystem.remove(131);

    cout << "\nAfter deletions:" << endl;
    bankingSystem.display();

    cout << "\nInserting additional account numbers 161 and 171:" << endl;
    bankingSystem.insert(161);
    bankingSystem.insert(171);

    cout << "\nAfter inserting additional account numbers:" << endl;
    bankingSystem.display();

    return 0;
}
