#include "../utils/utils.h"
using namespace std;

/* hash table
class Solution {
public:
    unordered_map<int, vector<int>> hash;
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            hash[nums[i]].emplace_back(i);
        }
    }
    
    int pick(int target) {
        return hash[target][rand() % hash[target].size()];
    }
};
*/

class Solution {
public:
    vector<int> & nums;
    Solution(vector<int>& nums) : nums(nums) { }
    
    int pick(int target) {
        int ans;
        for (int i = 0, cnt = 0; i < nums.size(); ++i){
            if (nums[i] == target){
                ++cnt;
                if (rand() % cnt == 0){
                    ans = i;
                }
            }
        }
        return ans;
    }
};