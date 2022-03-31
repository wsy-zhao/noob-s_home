#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int width = grid[0].size(), height = grid.size(), perimeter = 0;
        for (int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if (grid[i][j] == 0){
                    continue;
                }
                int count = 4;
                // up
                if (i - 1 >= 0 && grid[i - 1][j] == 1){
                    count--;
                }
                // down
                if (i + 1 < height && grid[i + 1][j] == 1){
                    count--;
                }
                // right
                if (j - 1 >= 0 && grid[i][j - 1] == 1){
                    count--;
                }
                // left
                if (j + 1 < width && grid[i][j + 1] == 1){
                    count--;
                }
                perimeter += count;
            }
        }
        return perimeter;
    }
};