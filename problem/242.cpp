#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> map;
        for(char i : s){
            map[i]++;
        }
        for(char i : t){
            if(map.find(i) == map.end()){
                return false;
            }
            else if(--map[i] < 0){
                return false;
            }
        }
        return true;
    }
};