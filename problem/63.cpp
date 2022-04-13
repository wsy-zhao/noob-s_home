#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size(), width = obstacleGrid[0].size();
        vector<vector<int>> f(height, vector<int>(width));
        int i = 0, j = 0;
        while (i < width){
            if (obstacleGrid[0][i]){
                break;
            }
            f[0][i++] = 1;
        }
        while (i < width){
            f[0][i++] = 0;
        }
        i = 0;
        while (i < height){
            if(obstacleGrid[i][0]){
                break;
            }
            f[i++][0] = 1;
        }
        while (i < height){
            f[i++][0] = 0;
        }
        for (i = 1; i < height; ++i){
            for(j = 1; j < width; ++j){
                if (obstacleGrid[i][j]){
                    f[i][j] = 0;
                }
                else{
                    f[i][j] = f[i-1][j] + f[i][j-1];
                }
            }
        }
        return f[height-1][width-1];
    }
};