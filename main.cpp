#include <iostream>
#include <vector>
#include ".\utils\utils.h"
#include ".\problem\57.cpp"
using namespace std;

int main(){
    Solution s;
    // vector<vector<int>> intervals = { {1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    // vector<int> newInterval = {4,8};
    // vector<vector<int>> intervals = { {1,3}, {6,9}};
    // vector<int> newInterval = {2,5};
    // vector<vector<int>> intervals = { {1,5}};
    // vector<int> newInterval = {2,7};
    vector<vector<int>> intervals = { {1,5}};
    vector<int> newInterval = {0,0};
    vector<vector<int>> ans = s.insert(intervals, newInterval);
    print_matrix(ans);
    return 0;
}
