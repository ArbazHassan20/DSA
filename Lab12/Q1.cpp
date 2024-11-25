#include <iostream>
#include <string>
using namespace std;

string reverseString(const string& str) {
    string reversed = str;
    int n = reversed.length();
    for (int i = 0; i < n / 2; i++) {
        swap(reversed[i], reversed[n - 1 - i]);
    }
    return reversed;
}

int naivePatternSearch(const string& text, const string& pattern) {
    string reversedPattern = reverseString(pattern); 
    int textLen = text.length();
    int patternLen = reversedPattern.length();

    for (int i = 0; i <= textLen - patternLen; i++) {
        int j = 0;
        while (j < patternLen && text[i + j] == reversedPattern[j]) {
            j++;
        }
        if (j == patternLen) {
            return i; 
        }
    }

    return -1;  
}

int main() {
    string text = "ABCDBACD";
    string pattern = "BAC";

    int index = naivePatternSearch(text, pattern);
    
    if (index != -1) {
        cout << "Reverse of pattern \"" << pattern << "\" found at index " << index << endl;
    } else {
        cout << "Reverse of pattern \"" << pattern << "\" not found in the text." << endl;
    }

    return 0;
}
