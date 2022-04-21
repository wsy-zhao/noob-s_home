#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int length = s.size();
        vector<int> ans(s.size());
        vector<int> anchor;
        for(int i = 0; i < length; ++i){
            if(s[i] == c){
                anchor.emplace_back(i);
            }
        }
        int anchor_size = anchor.size(), pos = 0, anchor_pos = 0;
        while(pos < anchor[0]){
            ans[pos] = anchor[anchor_pos] - pos;
            ++pos;
        }
        
        while(anchor_pos < anchor_size - 1){
            ans[pos] = min(abs(pos - anchor[anchor_pos]), abs(pos - anchor[anchor_pos + 1]));
            if (pos == anchor[anchor_pos + 1]){
                ++anchor_pos;
            }
            ++pos;
        }
        
        while(pos < length){
            ans[pos] = pos - anchor[anchor_size - 1];
            ++pos;
        }
        return ans;
    }
};