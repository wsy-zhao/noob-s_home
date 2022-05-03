#include <numeric>
#include <vector>
using namespace std;

/* 暴力法
class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        return accumulate(nums.begin() + left, nums.begin() + right + 1, 0);
    }
};
*/

// 前缀和
class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();
        this->nums.emplace_back(nums[0]);
        for(int i = 1; i < size; ++i){
            this->nums.emplace_back(this->nums[i - 1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return this->nums[right];
        }
        else{
            return this->nums[right] - this->nums[left - 1];
        }
    }
};