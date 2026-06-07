#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    pair<int, int> getTopTwoMaximums(vector<vector<int>>& dp, int col, int rows) {
        int max1 = INT_MIN, max2 = INT_MIN;
        int maxrow1 = -1;

        for (int i=0; i < rows; i++) {
                int val = dp[i][col - 1];
                if (val > max1) {
                    max2 = max1;
                    max1 = val;
                    maxrow1 = i;
                } else if (val > max2) {
                    max2 = val;
                }
        }
        return {maxrow1, max2};
    }

public:
    int maxPathSum(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        vector<vector<int>> dp(R, vector<int>(C));

        for (int i=0; i < R; i++) {
            dp[i][0] = grid[i][0];
        }

        for (int j=1; j < C; j++) {
            auto [maxrow1, max2] = getTopTwoMaximums(dp, j, R);

            for (int i=0; i < R; i++) {
                if (i != maxrow1) {
                    dp[i][j] = grid[i][j] + dp[maxrow1][j - 1];
                } else {
                    dp[i][j] = grid[i][j] + max2;
                }
            }
        }

        int ans = INT_MIN;
        for (int i=0; i < R; i++) {
            ans = max(ans, dp[i][C - 1]);
        }

        return ans;
    }
};

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i=0; i < R; i++) {
        for (int j=0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.maxPathSum(grid) << endl;

    return 0;
}
