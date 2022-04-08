#include <vector> 
using namespace std;

class Solution {
public:
    /* API
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++){
            ans.emplace_back(__builtin_popcount(i));
        }
        return ans;
    }
    */

    /* 暴力
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++){
            int tmp = i, cnt = 0;
            while (tmp){
                cnt += (tmp & 1);
                tmp = tmp >> 1;
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
    */
   
};