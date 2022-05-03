#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0, width = grid[0].size(), height = grid.size();
        for(int i = 0; i < height; ++i){
            int max_row = 0;
            int max_col = 0;
            for (int j = 0; j < width; ++j){
                max_row = max(max_row, grid[i][j]);
                max_col = max(max_col, grid[j][i]);
            }
            ans += max_row + max_col;
            ans += count_if(grid[i].begin(), grid[i].end(), bind2nd(greater<int>(), 0));
        }
        return ans;
    }
};