#include "../utils/utils.h"

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_map;
        unordered_map<string, int> word;
        string ans;
        int count = 0, length = paragraph.size();
        int begin = 0, end = 0;
        for (string & i : banned){
            banned_map.insert(i);
        }
        while(end < length){
            paragraph[end] = tolower(paragraph[end]);
            if(paragraph[end] == ' ' || paragraph[end] == '!' || paragraph[end] == '?' || paragraph[end] == '\'' || paragraph[end] == ',' || paragraph[end] == ';' || paragraph[end] == '.'){
                string sub = paragraph.substr(begin, end - begin);
                if (!sub.empty() && banned_map.find(sub) == banned_map.end()){
                    ++word[sub];
                    if (word[sub] > count){
                        count = word[sub];
                        ans = sub;
                    }
                }
                
                begin = end + 1;
            }
            ++end;
        }
        string sub = paragraph.substr(begin, end - begin);
        if (banned_map.find(sub) == banned_map.end()){
            ++word[sub];
            if (word[sub] > count){
                ans = sub;
            }
        }
        return ans;
    }
};