#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, last = -1;
        for(int i = 0; n > 0; n = n >> 1, ++i){
            if (n & 1 == 1){
                if (last != -1){
                    ans = max(ans, i - last);
                }
                last = i;            
            }
        }
        return ans;
    }
};