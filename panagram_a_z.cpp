#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
    bool checkIfPangram(string sentence) {
        int mask = 0;
        for (char c : sentence) {
            int bit = c - 'a';
            mask |= (1 << bit);
        }
        return mask == (1 << 26) - 1;
    }
};

int main() {
    Solution sol;
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    if (sol.checkIfPangram(sentence)) {
        cout << "The sentence is a pangram." << endl;
    } else {
        cout << "The sentence is not a pangram." << endl;
    }
    
    return 0;
}
