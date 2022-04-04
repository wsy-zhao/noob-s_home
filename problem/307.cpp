#include <vector> 
using namespace std;

// divide into multi-block
class NumArray {
private:
    int nums[100][300]= {{0}};
    long sum[100] = {0};
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i * 300 < size; ++i){
            int sum = 0;
            for(int j = 0, pos = i * 300; j < 300 && pos < size; ++j, ++pos){
                this->nums[i][j] = nums[pos];
                sum += nums[pos];
            }
            this->sum[i] = sum;
        }
    }
    
    void update(int index, int val) {
        int block = index / 300, pos = index % 300;
        sum[block] -= (nums[block][pos] - val);
        nums[block][pos] = val;
    }
    
    int sumRange(int left, int right) {
        long sum = 0;
        int block_begin = left / 300, block_end = right / 300;
        int pos_begin = left % 300, pos_end = right % 300;
        if (block_begin == block_end){
            for(int i = pos_begin; i <= pos_end; ++i){
                sum += nums[block_begin][i];
            }
        }
        else {
            for(int i = pos_begin; i < 300; ++i){
                sum += nums[block_begin][i];
            }
            for(int i = 0; i <= pos_end; ++i){
                sum += nums[block_end][i];
            }
        }
        for(int i = block_begin + 1; i < block_end; i++){
            sum += this->sum[i];
        }
        return sum;
    }
};