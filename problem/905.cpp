#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int head = 0, tail = nums.size() - 1;
        while(head < tail){
            while(head < tail && nums[head] % 2 == 0) ++head;
            while(head < tail && nums[tail] % 2 == 1) --tail;
            swap(nums[head], nums[tail]); 
        }
        return nums;
    }
};