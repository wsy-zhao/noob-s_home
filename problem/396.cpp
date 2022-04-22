#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long tmp = 0, sum = accumulate(nums.begin(), nums.end(), 0), ans = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i){
            tmp += i * nums[i];
        }
        ans = tmp;
        for (int i = size - 1; i > 0; --i){
            tmp += sum - size * nums[i];
            ans = max(ans, tmp);
        }
        return ans;
    }
};