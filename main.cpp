#include <iostream>
#include <vector>
#include <string>
#include ".\utils\utils.h"
#include ".\problem\1606.cpp"
using namespace std;

int main(){
    Solution s;
    int k = 3;
    vector<int> arrival = {1,2,3,4,8,9,10}, load = {5,2,10,3,1,2,2};
    vector<int> res = s.busiestServers(k, arrival, load);
    print_vector(res);
    return 0;
}
