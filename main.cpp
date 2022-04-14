#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include ".\utils\utils.h"
#include ".\problem\1672.cpp"
using namespace std;

int main(){
    Solution s;
    vector<vector<int>> accounts = {
        {1,2,3},
        {3,2,1}
    };
    cout << s.maximumWealth(accounts) << endl;
    return 0;
}
