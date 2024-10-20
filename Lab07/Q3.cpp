#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
    Student* next;
    Student(string studentName, int studentScore) : name(studentName), score(studentScore), next(NULL) {}
};

class StudentList {
public:
    Student* head;
    StudentList() : head(NULL) {}

    void addStudent(const string& studentName, int studentScore) {
        Student* newStudent = new Student(studentName, studentScore);
        newStudent->next = head;
        head = newStudent;
    }

    void display() const {
        if (!head) {
            cout << "No students in the list." << endl;
            return;
        }
        Student* current = head;
        while (current) {
            cout << current->name << " - Score: " << current->score << endl;
            current = current->next;
        }
    }

    void radixSort() {
        int maxScore = getMaxScore();
        for (int placeValue = 1; maxScore / placeValue > 0; placeValue *= 10)
            bucketSort(placeValue);
    }

private:
    int getMaxScore() const {
        int highestScore = 0;
        Student* current = head;
        while (current) {
            highestScore = max(highestScore, current->score);
            current = current->next;
        }
        return highestScore;
    }

    void bucketSort(int placeValue) {
        Student* buckets[10] = { NULL }, *bucketTails[10] = { NULL };

        Student* current = head;
        while (current) {
            int digit = (current->score / placeValue) % 10;
            Student* nextStudent = current->next;

            if (!buckets[digit]) {
                buckets[digit] = bucketTails[digit] = current;
            } else {
                bucketTails[digit]->next = current;
                bucketTails[digit] = current;
            }
            current->next = NULL;
            current = nextStudent;
        }

        head = NULL;
        Student* tail = NULL;
        for (int i = 0; i < 10; ++i) {
            if (!buckets[i]) continue;
            if (!head) head = buckets[i];
            else tail->next = buckets[i];
            tail = bucketTails[i];
        }
    }
};

int main() {
    StudentList studentList;

    studentList.addStudent("Ali", 87);
    studentList.addStudent("Bilal", 90);
    studentList.addStudent("Chawala", 74);
    studentList.addStudent("Daniyal", 100);
    studentList.addStudent("Elvish", 60);
    studentList.addStudent("Farhad", 45);
    studentList.addStudent("Galib", 88);

    cout << "Student scores before sorting:\n";
    studentList.display();

    studentList.radixSort();

    cout << "\nStudent scores after sorting (by score in ascending order):\n";
    studentList.display();

    return 0;
}
