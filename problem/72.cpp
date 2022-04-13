#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int length1 = word1.size(), length2 = word2.size();
        vector<vector<int>> state(length1 + 1, vector<int>(length2 + 1, 0));
        for(int i = 1; i < length1 + 1; ++i){
            state[i][0] = i;
        }
        for(int i = 1; i < length2 + 1; ++i){
            state[0][i] = i;
        }
        for(int i = 1; i < length1 + 1; ++i){
            for(int j = 1; j < length2 + 1; ++j){
                if(word1[i - 1] == word2[j - 1]){
                    state[i][j] = min({state[i - 1][j - 1], state[i-1][j] + 1, state[i][j-1] + 1});
                }
                else{
                    state[i][j] = 1 + min({state[i - 1][j - 1], state[i-1][j], state[i][j-1]});
                }
            }
        }
        return state[length1][length2];
    }
};