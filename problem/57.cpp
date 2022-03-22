#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // // from 56.cpp, time complexity O(nlogn)
        // intervals.push_back(newInterval);
        // sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){ return a[0] < b[0] ? true : false; });
        // vector<vector<int>> ans;
        // int size = intervals.size();
        // for(vector<int> i : intervals){
        //     if (ans.size() == 0){
        //         ans.emplace_back(i);
        //     }
        //     else{
        //         if (i[0] > ans[ans.size() - 1][1]){
        //             // if section i out of the last section, adding a new section
        //             ans.emplace_back(i);
        //         }
        //         else if (i[1] > ans[ans.size() - 1][1]){
        //             // is section i can extend the last section, merging two section
        //             ans[ans.size() - 1][1] = i[1];
        //         }
        //     }
        // }
        // return ans;

        // new approach, time complexity O(n)
        if (intervals.size() == 0) { return {{newInterval[0], newInterval[1]}}; }
        int first = -1, second = -1, index = 0, length = intervals.size();
        
        // we want to find `first` and `second`, enable 
        // find the insert position
        /** TODO: binary search for to O(logn) **/

        while(index < length && intervals[index][1] < newInterval[0]) { ++index; }
        first = index;
        // find the right position
        while(index < length && intervals[index][1] < newInterval[1]) { ++index; };
        second = index;
        

        // overlap and expand
        // intercept by single point
        if (first == second){
            // overlap, need to combine
            if (first < length && intervals[first][0] <= newInterval[1]){
                if (intervals[first][0] <= newInterval[1] && newInterval[1] <= intervals[first][1] && newInterval[0] < intervals[first][0]){
                // expand the lower [[3,4]] [1,3] --> [[1,4]]
                        intervals[first][0] = newInterval[0];
                }
                // [[1,3]] [3,4] --> [[1,4]]
                else if(newInterval[1] >= intervals[first][1] && newInterval[0] <= intervals[first][1]){
                    intervals[first][1] = newInterval[1];
                }
            }
            // [[1,2]] [3,4](index = 1) or [[3,4]] [1,2](index=0) --> [[1,2],[3,4]]
            else{
                intervals.insert(intervals.begin()+first, newInterval);
            }
        }
        // intercept by two points
        else{
            // [[1,5],[10,15]] [3,11] --> [[1,15]]
            // [[1,5],[10,15]] [-1,16] --> [[-1, 16]]
            vector<int> vec = intervals[first];
            vec[0] = newInterval[0] < vec[0] ? newInterval[0] : vec[0];
            if(second < length){
                vec[1] = newInterval[1] > intervals[second][1] || newInterval[1] < intervals[second][0] ? 
                     newInterval[1] : intervals[second][1] ;
            }
            else{
                vec[1] = newInterval[1];
            }
            if(second < length && intervals[second][0] <= newInterval[1]) {
                ++second;
            }
            intervals.erase(intervals.begin()+first, intervals.begin()+second);
            intervals.insert(intervals.begin()+first, vec);
        }
        return intervals;
    }
};