#include <iostream>
#include <vector>
#include <string>
#include ".\utils\utils.h"
#include ".\problem\476.cpp"
using namespace std;

int main(){
    Solution s;
    vector<vector<int>> grid = { {0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0} };
    print_matrix(grid);
    cout << s.islandPerimeter(grid) << endl;
    return 0;
}
