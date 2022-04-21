#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    string toGoatLatin(string sentence) {
        sentence += " ";
        int length = sentence.size();
        int begin = 0;
        string ans, index = "a";
        for (int i = 0; i < length; ++i){
            if (sentence[i] == ' '){
                string word = sentence.substr(begin, i - begin);
                begin = i + 1;
                switch (word[0]){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    break;
                default:
                    word += word[0];
                    word.erase(0, 1);
                    break;
                }
                word = word + "ma" + index + " ";
                index += "a";
                ans += word;
            }
        }
        ans.erase(ans.size(),1);
        return ans;
    }
};