#include <iostream>
#include <vector>
#include <string>
#include ".\utils\utils.h"
#include ".\problem\61.cpp"
using namespace std;

int main(){
    // ListNode l5(5, nullptr); 
    // ListNode l4(4, &l5); 
    // ListNode l3(3, &l4); 
    // ListNode l2(2, &l3);
    // ListNode l1(1, &l2);


    // ListNode l3(2, nullptr); 
    // ListNode l2(1, &l3);
    // ListNode l1(0, &l2);

    ListNode l2(2, nullptr);
    ListNode l1(1, &l2);

    print_list(&l1);
    Solution s;
    print_list(s.rotateRight(&l1, 2));
    return 0;
}
