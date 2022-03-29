#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum_of_n = mean * (rolls.size() + n) - accumulate(rolls.begin(), rolls.end(), 0);
        if (6 * n < sum_of_n || n > sum_of_n){
            return vector<int>();
        }
        else{
            int base = sum_of_n / n, i = 0;
            vector<int> ans(n, base);
            while (i < n && base * n + i < sum_of_n){
                ++ans[i++];
            }
            return ans;
        }
    }
};