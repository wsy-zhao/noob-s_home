#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include ".\utils\utils.h"
#include ".\problem\429.cpp"
using namespace std;

int main(){
    Solution s;
    Node n2(2), n6(6), n14(14), n12(12), n13(13), n10(10);
    Node n11(11, {&n14}), n8(8, {&n12}), n9(9, {&n13});
    Node n7(7, {&n11}), n4(4, {&n8}), n5(5, {&n9, &n10});
    Node n3(3, {&n6, &n7});
    Node n1(1, {&n2, &n3, &n4, &n5});
    cout << s.levelOrder(&n1) << endl;
    return 0;
}
