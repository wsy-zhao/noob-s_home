#include <iostream>
#include <vector>
#include <string>
#include ".\utils\utils.h"
// #include ".\problem\476.cpp"
using namespace std;

// template<typename T> 
// ostream &operator<<(ostream &os, const vector<T> &v){
//     os << "[ ";
//     for (T i : v){
//         os << i << " "; 
//     }
//     os << "]" << endl;
//     return os;
// }

// template<typename T>
// ostream &operator<<(ostream &os, const vector<vector<T>> &v){
//     for (vector<T> i : v){
//         os << "[ ";
//         for (T j : i){
//             os << j << " ";
//         }
//         os << "]" << endl;
//     }
//     return os;
// }

int main(){
    vector<int> v1 = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> v2 = { {1,2,3}, {4,5,6}, {7,8,9} };
    cout << v1 << v2;
    return 0;
}
