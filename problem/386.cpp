#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int number = 1;
        for(int i = 0; i < n; ++i){
            ans.emplace_back(number);
            if (number * 10 <= n){
                number *= 10;
            }
            else{
                while(number % 10 == 9 || number + 1 > n){
                    number /= 10;
                }
                number++;
            }
        }
        return ans;
    }
};