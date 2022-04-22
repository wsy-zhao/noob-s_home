#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include ".\utils\utils.h"
#include ".\problem\396.cpp"
using namespace std;

int main(){
    Solution s;
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    cout << s.maxRotateFunction(vec) << endl;
    return 0;
}
