class Solution {
private:
    const int diff[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    void dfs(vector<vector<char>>& grid, int r, int c, int i, int j) {
        grid[i][j] = '0';
        
        for (int w = 0; w < 8; w++) {
            int ar = i + diff[w][0];
            int ac = j + diff[w][1];
            
            if (ar >= 0 && ar < r && ac >= 0 && ac < c && grid[ar][ac] == '1') {
                dfs(grid, r, c, ar, ac);
            }
        }
    }

public:
    int numIslands8Way(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int r = grid.size();
        int c = grid[0].size();
        int islands = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, r, c, i, j);
                }
            }
        }
        
        return islands;
    }
};
