#include <iostream>
#include <vector>
#include ".\utils\utils.h"
#include ".\problem\2038.cpp"
using namespace std;

int main(){
    Solution s;
    string str = "AAABABB";
    cout << s.winnerOfGame(str) << endl;
    return 0;
}
