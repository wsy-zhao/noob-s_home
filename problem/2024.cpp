#include <string>
using namespace std;

class Solution {
public:
    int helper(string answerKey, int k, char ch){
        int ans = 0, length = answerKey.length();
        for(int right = 0, left = 0, sum = 0; right < length; right++){
            sum += answerKey[right] != ch;
            while (sum > k){
                sum -= answerKey[left++] != ch;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey, k, 'F'), helper(answerKey, k, 'T'));
    }
};