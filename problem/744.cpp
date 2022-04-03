#include <vector>
#include <algorithm>
using namespace std;

// 1. 暴力
// 2. 二分
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        /* 暴力
        int size = letters.size();
        if(target >= letters[size - 1]){
            return letters[0];
        }
        int i = -1;
        while (++i < size && letters[i] <= target);
        return letters[i];
        */

        /* 手写二分
        int size = letters.size();
        if (target >= letters[size  - 1] || target < letters[0]) {
            return letters[0];
        }
        int head = 0, tail = size - 1;
        while (head < tail && tail - head > 1){
            int mid = (head + tail) / 2;
            if (letters[mid] > target){
                tail = mid;
            }
            else {
                head = mid + 1;
            }
        }
        return letters[head] > target ? letters[head] : letters[tail];
        */

        // API二分
        return target < letters.back() ? *(upper_bound(letters.begin(), letters.end() - 1, target)) : letters[0];
        
    }
};