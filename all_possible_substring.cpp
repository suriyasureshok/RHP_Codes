#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> allPossibleSubstrings(string s) {
        vector<string> result;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                result.push_back(s.substr(i, j - i + 1));
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string input;
    
    cout << "Enter a string: ";
    getline(cin, input);
    
    vector<string> substrings = sol.allPossibleSubstrings(input);
    
    cout << "All possible substrings:" << endl;
    for (const string& substring : substrings) {
        cout << substring << endl;
    }
    
    return 0;
}
