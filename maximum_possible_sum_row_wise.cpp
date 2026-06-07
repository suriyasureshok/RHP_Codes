#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    pair<int, int> getTopTwoMaximums(vector<vector<int>>& dp, int row, int cols) {
        int max1 = INT_MIN, max2 = INT_MIN;
        int max1Col = -1;
        
        for (int j = 0; j < cols; j++) {
            int val = dp[row - 1][j];
            if (val > max1) {
                max2 = max1;
                max1 = val;
                max1Col = j;
            } else if (val > max2) {
                max2 = val;
            }
        }
        
        return {max1Col, max2};
    }
    
public:
    int maxPathSum(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
        vector<vector<int>> dp(R, vector<int>(C));
        
        for (int j = 0; j < C; j++) {
            dp[0][j] = grid[0][j];
        }
        
        for (int i = 1; i < R; i++) {
            auto [max1Col, max2] = getTopTwoMaximums(dp, i, C);
            
            for (int j = 0; j < C; j++) {
                if (j != max1Col) {
                    dp[i][j] = grid[i][j] + dp[i - 1][max1Col];
                } else {
                    dp[i][j] = grid[i][j] + max2;
                }
            }
        }
        
        int ans = INT_MIN;
        for (int j = 0; j < C; j++) {
            ans = max(ans, dp[R - 1][j]);
        }
        
        return ans;
    }
};

int main() {
    int R, C;
    cin >> R >> C;
    
    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    
    Solution solution;
    cout << solution.maxPathSum(grid) << endl;
    
    return 0;
}