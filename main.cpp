#include <iostream>
#include <vector>
#include <string>
#include ".\utils\utils.h"
#include ".\problem\2024.cpp"
using namespace std;

int main(){
    Solution s;
    string answerKey = "TFTF";
    int k = 2;
    cout << s.maxConsecutiveAnswers(answerKey, k) << endl;
    return 0;
}
