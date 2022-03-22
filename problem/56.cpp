#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){ return a[0] < b[0] ? true : false; });
        vector<vector<int>> ans;
        int size = intervals.size();
        for(vector<int> i : intervals){
            if (ans.size() == 0){
                ans.emplace_back(i);
            }
            else{
                if (i[0] > ans[ans.size() - 1][1]){
                    // if section i out of the last section, adding a new section
                    ans.emplace_back(i);
                }
                else if (i[1] > ans[ans.size() - 1][1]){
                    // is section i can extend the last section, merging two section
                    ans[ans.size() - 1][1] = i[1];
                }
            }
        }
        return ans;
    }
};