#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

struct Book {
    int id;       
    string title;
};

class HashTable {
private:
    vector<list<Book>> table; 
    
    int hashFunction(int id) {
        return id / 100 % size; }

public:
    HashTable(int size) : size(size) {
        table.resize(size);
    }

    // Insert a book into the hash table
    void insert(int id, string title) {
        int index = hashFunction(id);
        table[index].push_back({id, title});
    }

    bool search(int id) {
        int index = hashFunction(id);
        for (auto &book : table[index]) {
            if (book.id == id) {
                cout << "Book Found: ID=" << book.id << ", Title=" << book.title << endl;
                return true;
            }
        }
        cout << "Book with ID " << id << " not found." << endl;
        return false;
    }

    void remove(int id) {
        int index = hashFunction(id);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->id == id) {
                cout << "Deleting Book: ID=" << it->id << ", Title=" << it->title << endl;
                table[index].erase(it);
                return;
            }
        }
        cout << "Book with ID " << id << " not found for deletion." << endl;
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Index " << i << ": ";
            for (auto &book : table[i]) {
                cout << "[" << book.id << ", " << book.title << "] ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable catalog(10);

    // Insert records
    catalog.insert(100, "Book A1");
    catalog.insert(101, "Book A2");
    catalog.insert(102, "Book A3");
    catalog.insert(200, "Book B1");
    catalog.insert(201, "Book B2");
    catalog.insert(300, "Book C1");
    catalog.insert(301, "Book C2");
    catalog.insert(302, "Book C3");
    catalog.insert(303, "Book C4");

    cout << "\nAfter inserting books:" << endl;
    catalog.display();

    // Search for books
    cout << "\nSearching for books:" << endl;
    catalog.search(101); // Existing book
    catalog.search(301); // Existing book
    catalog.search(400); // Non-existent book

    // Delete books
    cout << "\nDeleting books:" << endl;
    catalog.remove(101); // Delete book A2
    catalog.remove(301); // Delete book C2

    cout << "\nAfter deletions:" << endl;
    catalog.display();

    return 0;
}
