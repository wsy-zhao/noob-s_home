#include "../utils/utils.h"
#include <unordered_set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const static string MORSE[] = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
            "....", "..", ".---", "-.-", ".-..", "--", "-.",
            "---", ".--.", "--.-", ".-.", "...", "-", "..-",
            "...-", ".--", "-..-", "-.--", "--.."
        };
        unordered_set<string> hash;
        for (string & word : words){
            string tmp_morse;
            for(char & ch : word){
                tmp_morse += MORSE[ch - 'a'];
            }
            hash.emplace(tmp_morse);
        }
        return hash.size();
    }
};