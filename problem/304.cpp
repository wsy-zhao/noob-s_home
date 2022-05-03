#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> numMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int height = matrix.size(), width = matrix[0].size();
        numMatrix.resize(height + 1, vector<int>(width + 1));
        for (int i = 1; i <= height; ++i){
            for (int j = 1; j <= width; ++j){
                numMatrix[i][j] = matrix[i-1][j-1] + numMatrix[i - 1][j] + numMatrix[i][j - 1] - numMatrix[i - 1][j - 1];
            }
        }
    }
    
    // int sumRegion(int row1, int col1, int row2, int col2) {
    //     if (row1 == 0 || col1 == 0){
    //         if(row1 == 0 && col1 != 0){
    //             return numMatrix[row2][col2] - numMatrix[row2][col1 - 1];
    //         }
    //         else if(row1 != 0 && col1 == 0){
    //             return numMatrix[row2][col2] - numMatrix[row1 - 1][col2];
    //         }
    //         else{
    //             return numMatrix[row2][col2];
    //         }
    //     }
    //     else{
    //         return numMatrix[row2][col2] - numMatrix[row1 - 1][col2] - numMatrix[row2][col1 - 1] + numMatrix[row1 - 1][col1 - 1];
    //     }
    // }

    int sumRegion(int row1, int col1, int row2, int col2){
        return numMatrix[row2 + 1][col2 + 1] - numMatrix[row1][col2 + 1] - numMatrix[row2 + 1][col1] + numMatrix[row1][col1];
    }
};