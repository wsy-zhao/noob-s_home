#include <iostream>
#include <vector>
#include <string>
#include ".\utils\utils.h"
#include ".\problem\682.cpp"
using namespace std;

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> b = {{1,2,3},{4,5,6},{7,8,9}};
    print_vector(a);
    print_matrix(b);
    return 0;
}
