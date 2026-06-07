#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> allSubsequences(string s)
    {
        vector<string> result;
        int L = s.length();

        for (int mask = 1; mask < (1 << L); mask++)
        {
            string subseq = "";
            for (int bit = 0; bit < L; bit++)
            {
                if (mask & (1 << bit))
                {
                    subseq += s[bit];
                }
            }
            result.push_back(subseq);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    vector<string> subsequences = sol.allSubsequences(input);

    cout << "All possible subsequences:" << endl;
    for (const string &subsequence : subsequences)
    {
        cout << subsequence << endl;
    }

    return 0;
}
