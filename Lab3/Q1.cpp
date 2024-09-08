#include "iostream"
using namespace std;

class ListNode{
    int value;
    ListNode* nextNode;
    
    public:
    ListNode():value(0), nextNode(NULL){}
    ListNode(const int val): value(val), nextNode(NULL){}
    
    friend class LinkedList;
};

class LinkedList{
    ListNode* headNode;
    
    public:
    LinkedList():headNode(NULL){}
    LinkedList(ListNode* node): headNode(node){}
    
    void addAtFront(const int val){
        ListNode* newNode = new ListNode(val);
        if(headNode == NULL) headNode = newNode;
        else{
            newNode->nextNode = headNode;
            headNode = newNode;
        }
    }

    void addAtEnd(const int val){
        ListNode* newNode = new ListNode(val);
        if(headNode == NULL) headNode = newNode;
        else{
            ListNode* current = headNode;
            while(current->nextNode != NULL){
                current = current->nextNode;
            }
            current->nextNode = newNode;
        }
    }

    void addAfterValue(const int targetValue, const int insertValue){
        ListNode* newNode = new ListNode(insertValue);
        if(headNode == NULL){
            headNode = newNode;
        }
        else{
            ListNode* current = headNode;
            while(current->value != targetValue){
                current = current->nextNode;
            }
            ListNode* temp = current->nextNode;
            current->nextNode = newNode;
            newNode->nextNode = temp;
        }
    }

    void addBeforeValue(const int targetValue, const int insertValue){
        ListNode* newNode = new ListNode(insertValue);
        if(headNode == NULL){
            headNode = newNode;
        }
        else{
            ListNode* current = headNode;
            while(current->nextNode->value != targetValue){
                current = current->nextNode;
            }
            newNode->nextNode = current->nextNode;
            current->nextNode = newNode;
        }
    }

    int countNodes(){
        int count = 0;
        ListNode* current = headNode;
        while(current != NULL){
            count++;
            current = current->nextNode;
        }
        return count;
    }

    void removeFromFront(){
        if(headNode != NULL){
            ListNode* temp = headNode;
            headNode = temp->nextNode;
            delete temp;
        }
        else{
            cout << "The list is empty" << endl;
        }
    }

    void removeFromEnd(){
        if(headNode != NULL){
            ListNode* current = headNode;
            while(current->nextNode->nextNode != NULL){
                current = current->nextNode;
            }
            delete current->nextNode;
            current->nextNode = NULL;
        }
        else{
            cout << "The list is empty" << endl;
        }
    }

    void removeValue(const int targetValue){
        if (headNode == NULL){
            cout << "The list is empty" << endl;
            return;
        }
        ListNode* current = headNode;
        while(current->nextNode->value != targetValue){
            current = current->nextNode;
        }
        ListNode* temp = current->nextNode;
        current->nextNode = temp->nextNode;
        delete temp;
    }

    void displayList(){
        ListNode* current = headNode;
        while(current != NULL){
            cout << current->value << " ";
            current = current->nextNode;
        }
    }
};

int main() {
    LinkedList list;
    
   
