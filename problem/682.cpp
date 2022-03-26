#include <vector>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        for(auto i : ops){
            if("C" == i){
                score.pop_back();
            }
            else if("D" == i){
                score.push_back(2 * score[score.size() - 1]);
            }
            else if("+" == i){
                score.push_back(score[score.size() - 1] + score[score.size() - 2]);
            }
            // it is a number
            else{
                score.push_back(atoi(i.c_str()));
            }
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};