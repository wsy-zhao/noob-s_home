#include <iostream>
#include <vector>
#include <string>
#include ".\utils\utils.h"
#include ".\problem\307.cpp"
using namespace std;

int main(){
    vector<int> nums = {0,9,5,7,3};
    NumArray obj(nums);
    cout << obj.sumRange(4,4) << endl;
    cout << obj.sumRange(2,4) << endl;
    cout << obj.sumRange(3,3) << endl;
    obj.update(4,5);
    obj.update(1,7);
    obj.update(0,8);
    cout << obj.sumRange(1,2) << endl;
    obj.update(1,9);
    cout << obj.sumRange(4,4) << endl;
    obj.update(3,4);
    return 0;
}
