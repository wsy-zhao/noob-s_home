#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bank_set;
        unordered_set<string> after_travel;
        queue<string> q;
        int step = 0;
        char gene[] = {'A', 'T', 'C', 'G'};
        for(string & i : bank){
            bank_set.emplace(i);
        }
        if (bank_set.find(end) == bank_set.end()){
            return -1;
        }
        if (start == end){
            return 0;
        }
        q.emplace(start);
        while(!q.empty()){
            for(int i = 0, sz = q.size(); i < sz; ++i){
                for(int i = 0; i < 8; ++i){
                    for(int j = 0; j < 4; ++j){
                        if (q.front()[i] == gene[j]){
                            continue;
                        }
                        string trans = q.front();
                        trans[i] = gene[j];
                        if(trans == end){
                            return step + 1;
                        }
                        else if(bank_set.find(trans) != bank_set.end() && after_travel.find(trans) == after_travel.end()){
                            q.emplace(trans);
                        }
                    }
                }
                after_travel.emplace(q.front());
                q.pop();
            }
            ++step;
        }
        return -1;
    }
};