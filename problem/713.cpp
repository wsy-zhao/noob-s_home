#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    // out of time limitation
    /*
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        unsigned long cnt = 0;
        for(int i = 0; i < size; ++i){
            long mul = nums[i];
            if(mul < k){
                ++cnt;
            }
            for(int j = i + 1; j < size && mul < k; ++j){
                mul *= nums[j];
                if (mul < k){
                    ++cnt;
                }
                else{
                    break;
                }                
            }
        }
        return cnt;
    }
    */
    // method 1, fix the right
    /*
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), ret = 0;
        int prod = 1, left = 0;
        for (int right = 0; right < n; right++) {
            prod *= nums[j];
            while (left <= right && prod >= k) {
                prod /= nums[left];
                left++;
            }
            ret += right - left + 1;
        }
        return ret;
    }
    */
   // method2, fix the left
    int numSubarrayProductLessThanK(vector<int>& nums, int k){
        int cnt = 0;
        for(int left = 0, right = 0, product = 1, n = nums.size(); left < n; product /= nums[left], left++){
            if (right < left){
                right = left;
            }
            if(product == 0){
                product = 1;
            }
            while(right < n && nums[right] * product < k){
                product *= nums[right];
                ++right;
            }
            cnt += right - left;
        }
        return cnt;
    }
};