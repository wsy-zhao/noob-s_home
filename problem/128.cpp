#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    /* pre-treatment and one search
     * time complexity O(nlogn + n) -> O(nlogn)
     * space complexity O(1)
     */
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (0 == nums.size()){
            return 0;
        }
        else if(1 == nums.size()){
            return 1;
        }
        sort(nums.begin(), nums.end());
        int length = 1, max_length = 0, last = nums[0];
        for(int i = 1; i < size; ++i){
            if (last == nums[i]){
                continue;
            }
            else if(last + 1 == nums[i]){
                ++length;
                last = nums[i];
            }
            else{
                max_length = max(max_length, length);
                length = 1;
                last = nums[i];
            }
        }
        return max(max_length, length);
    }
    /**/
    // unordered set
    // int longestConsecutive(vector<int>& nums){
    //     unordered_set<int> nums_set;
    //     for(int i : nums){
            
    //     }
    // }
};