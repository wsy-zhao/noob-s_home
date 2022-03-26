#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const int height = img.size(), width = img[0].size();
        vector<vector<int>> ans (height, vector<int>(width, -1));
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                int sum = 0, count = 0;
                for(int h = max(i-1, 0), max_h = min(i+2, height); h < max_h; h++){
                    for(int w = max(j-1, 0), max_w = min(j+2, width); w < max_w; w++){
                        sum+=img[h][w];
                        count++;
                    }
                }
                ans[i][j] = sum/count;
            }
        }
        return ans;
    }
};