#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mapChar2String;
        unordered_map<string, char> mapString2Char;
        int count_pattern = 0, count_s = 0, length_pattern = pattern.length(), length_s = s.length();
        while(count_pattern < length_pattern && count_s < length_s){
            while (s[count_s] == ' '){
                ++count_s;
            }
            int s_begin = count_s;
            while (count_s < length_s && s[count_s] != ' '){
                ++count_s;
            }
            string temp_string = s.substr(s_begin, count_s - s_begin);
            bool find_map1 = mapChar2String.find(pattern[count_pattern]) != mapChar2String.end(), 
                 find_map2 =  mapString2Char.find(temp_string) != mapString2Char.end();
            if (find_map1 && find_map2){
                if(pattern[count_pattern] != mapString2Char[temp_string]){
                    return false;
                }
            }
            else if ( (!find_map1) && (!find_map2) ){
                mapChar2String[pattern[count_pattern]] = temp_string;
                mapString2Char[temp_string] = pattern[count_pattern];
            }
            else{
                return false;
            }
            ++count_pattern;
        }
        if (count_pattern != length_pattern || count_s != length_s){
            return false;
        }
        return true;
    }
};