#include <iostream>
#include <vector>
#include ".\utils\utils.h"
#include ".\problem\56.cpp"
using namespace std;

int main(){
    Solution s;
    vector<vector<int>> intervals = { {1,4}, {4,5}};
    vector<vector<int>> ans = s.merge(intervals);
    print_matrix(ans);
    return 0;
}
