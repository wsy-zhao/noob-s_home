#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i < right + 1; ++i){
            int temp = i;
            do{
                int bit = temp % 10;
                if (0 == bit || 0 != i % bit){
                    break;
                }
                temp /= 10;
            } while (temp > 0);
            if (temp == 0){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};