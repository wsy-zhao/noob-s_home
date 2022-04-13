#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int length = 0;
        vector<int> ans = {1,0};
        for(int i = 0; i < s.length(); ++i){
            length += widths[s[i] - 'a'];
            if(length > 100){
                length = widths[s[i] - 'a']; 
                ++ans[0];
            }
            else if (length == 100){
                if (i == s.length() - 1){
                    ans[1] = length;
                    return ans;
                }
                else{
                    ++ans[0];
                    length = 0; 
                }
            }
        }
        ans[1] = length;            
        return ans;
    }
};