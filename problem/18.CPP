#include <vector>
#include <algorithm>
using namespace std;

// enumeration + Double pointer
// 枚举 + 双指针
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int size = nums.size() - 1;
        if(size < 3){
            return vector<vector<int>>();
        }
        else{
            sort(nums.begin(), nums.end());
        }
        // enumerate the first number
        for(int location1 = 0; location1 < size - 2; ++location1){
            // eliminate duplication
            if(location1 != 0 && nums[location1] == nums[location1 - 1]){
                continue;
            }
            // enumerate the second number
            for(int location2 = location1 + 1; location2 < size - 1; ++location2){
                // eliminate duplication
                if (location2 != location1 + 1 && nums[location2] == nums[location2 - 1]){
                    continue;
                }
                // out of scope of `int`, use `long` 
                long first_2 = nums[location1] + nums[location2];
                // enumerate the first number as `left` and enumerate the second number as `right`
                for(int left = location2 + 1, right = size; left < right; ++left){
                    // eliminate duplication
                    if (location2 + 1 != left && nums[left] == nums[left - 1]){
                        continue;
                    }
                    // the right number is so big, we don`t want the result less than target 
                    while (first_2 + nums[left] + nums[right] < target && left < right){
                        ++left;
                    }
                    // find the last number
                    while (first_2 + nums[left] + nums[right] > target && left < right){
                        --right;
                    }
                    if (left < right && first_2 + nums[left] + nums[right] == target){
                        ans.push_back({nums[location1], nums[location2], nums[left], nums[right]});
                    }
                }
            }
        }
        return ans;
    }
};