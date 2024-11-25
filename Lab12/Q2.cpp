#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int length = 0; 
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length] || pattern[i] == '?') {
           
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMPSearchWithWildcard(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

   
    vector<int> lps = computeLPSArray(pattern);

    int i = 0; 
    int j = 0;  

    while (i < n) {
        if (pattern[j] == text[i] || pattern[j] == '?') {
            i++;
            j++;
        }

        if (j == m) {
            // Match found at index (i - j)
            cout << "Match found at index " << i - j << endl;
            j = lps[j - 1]; 
        } else if (i < n && (pattern[j] != text[i] && pattern[j] != '?')) {
        
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    cout << "No match found." << endl;
}

int main() {
    string text = "ABCD";
    string pattern = "A?C";

    KMPSearchWithWildcard(text, pattern);

    return 0;
}
