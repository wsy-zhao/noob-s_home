using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for (int i = 5; i <= n ; i+=5){
            while(0 == i%5){
                ans ++;
                i/=5;
            }
        }
        return ans;
    }
};