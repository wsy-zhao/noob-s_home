#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int minimum = 0, maximum = s.size(), i = 0;
        vector<int> ans(maximum + 1, 0);
        for(char & c : s){
            if (c == 'I'){
                ans[i++] = minimum++;
            }
            else{
                ans[i++] = maximum--;
            }
        }
        if(*(s.end()-1) == 'I'){
            ans[i] = minimum;
        }
        else{
            ans[i] = maximum;
        }
        return ans;
    }
};