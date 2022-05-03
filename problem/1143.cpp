#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.size(), length2 = text2.size();
        vector<vector<int>> score(length1, vector<int>(length2));
        if (text1[0] == text2[0]){
            score[0][0] = 1;
        }
        else{
            score[0][0] = 0;
        }
        for(int i = 1; i < length1; ++i){
            if (text1[i] == text2[0]){
                score[i][0] = score[i - 1][0] + 1;
            }
            else{
                score[i][0] = score[i - 1][0];
            }
        }
        for(int i = 1; i < length2; ++i){
            if (text2[i] == text1[0]){
                score[0][i] = score[0][i - 1];
            }
            else{
                score[0][i] = score[0][i - 1];
            }
        }
        for(int i = 1; i < length1; ++i){
            for (int j = 1; j < length2; ++j){
                if (text1[i] == text2[j]){
                    score[i][j] = score[i - 1][j - 1] + 1;
                }
                else{
                    score[i][j] = max({score[i - 1][j], score[i][j - 1]});
                }
            }
        }
        return score[length1 - 1][length2 - 1];
    }
};