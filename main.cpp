#include <iostream>
#include <vector>
#include <string>
#include ".\utils\utils.h"
#include ".\problem\744.cpp"
using namespace std;

int main(){
    vector<char> letters = {'e', 'e', 'e', 'k', 'q', 'q', 'q', 'v', 'v', 'y'};
    char target = 'e';
    Solution s;
    cout << letters << endl << target << " " <<  s.nextGreatestLetter(letters, target) << endl;
    return 0;
}
