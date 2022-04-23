#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    /* the reason why we calculate cross product is for calculating the sin value(get
     * the sign of vector<pq> and <qr>)
     */
    int cross(vector<int> &p, vector<int> &q, vector<int> &r){
        return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int size = trees.size();
        if (size < 4){
            return trees;
        }
        vector<vector<int>> ans;
        vector<bool> visit(size, false);
        int left = 0;
        // find the most left point
        for(int i = 0; i < size; ++i){
            if (trees[i][0] < trees[left][0]){
                left = i;
            }
        }
        int p = left;

        do{
            // find `p` point
            int q = (p + 1) % size;
            for(int r = 0; r < size; ++r){
                if (cross(trees[p], trees[q], trees[r]) < 0){
                    q = r;
                }
            }
            
            // find point in the same line
            for(int r = 0; r < size; ++r){
                if (visit[r] || q == r || p ==r){
                    continue;
                }
                if (cross(trees[p], trees[q], trees[r]) == 0){
                    ans.emplace_back(trees[r]);
                    visit[r] = true;
                }
            }
            if (!visit[q]){
                ans.emplace_back(trees[q]);
                visit[q] = true;
            }
            p = q;
        } while (p != left);
        return ans;
    }
};