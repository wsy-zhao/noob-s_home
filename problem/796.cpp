#include <string>
using namespace std;

class Solution {
public:
    /* 暴力法
    bool rotateString(string s, string goal) {
        int length_s = s.length(), length_g = s.length();
        if (length_s != length_g){
            return false;
        }
        
        for(int i = 0; i < length_s; i++){
            int j = 0;
            while (j < length_g && s[(i+j) % length_g] == goal[j]){
                j++;
            }
            if (j == length_g){
                return true;
            }
        }
        return false;
    }
    */
    bool rotateString(string s, string goal){
        return s.size() == goal.size() && (s + s).find(goal) != string:: npos;
    }
};