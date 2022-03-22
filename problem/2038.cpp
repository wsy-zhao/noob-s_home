#include <string>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        for (int i = 1, length = colors.size() - 1; i < length; ++i){
            if (colors[i-1] == 'A' && colors[i] == 'A'  && colors[i+1] == 'A'){
                ++a;
                continue;
            }
            if (colors[i-1] == 'B' && colors[i] == 'B' &&colors[i+1] == 'B'){
                ++b;
                continue;
            }
        }
        return a > b ? true : false;
    }
};