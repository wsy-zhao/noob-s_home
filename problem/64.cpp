#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size(), width = grid[0].size();
        // TODO: 滚动数组，只用两行完成
        vector<vector<int>> ans(height, vector<int>(width));
        ans[0][0] = grid[0][0];
        for(int i = 1; i < width; ++i){
            ans[0][i] = grid[0][i] + ans[0][i - 1];
        }
        for(int i = 1; i < height; ++i){
            ans[i][0] = grid[i][0] + ans[i - 1][0];
        }
        for(int i = 1; i < height; ++i){
            for (int j = 1; j < width; ++j){
                ans[i][j] = min(grid[i][j] + ans[i][j - 1], grid[i][j] + ans[i - 1][j]);
            }
        }
        return ans[height - 1][width - 1];
    }
};