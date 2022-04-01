#include <iostream>
#include <vector>
#include <string>
#include ".\utils\utils.h"
// #include ".\problem\476.cpp"
using namespace std;

int main(){
    ListNode l5(5, nullptr);
    ListNode l4(4, &l5);
    ListNode l3(3, &l4);
    ListNode l2(2, &l3);
    ListNode l1(1, &l2);
    vector<int> v1 = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> v2 = { {1,2,3},{4,5,6},{7,8,9} };
    cout << &l1 << endl << v1 << endl <<v2;
    return 0;
}
