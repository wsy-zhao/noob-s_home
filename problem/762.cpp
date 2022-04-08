using namespace std;

class Solution {
public:
    bool isPrime(int n){
        for(int i = 2; i*i <= n; ++i){
            if(!(n % i)) return false;
        }
        return n == 1 ? false : true;
    }

    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i){
            if (isPrime(__builtin_popcount(i))) {
                ++count;
            }
        }
        return count;
    }

    // int countPrimeSetBits(int left, int right) {
    //     int count = 0;
    //     for (int i = left; i <= right; ++i){
    //         if (1 << __builtin_popcount(i) & 665772) {
    //             ++count;
    //         }
    //     }
    //     return count;
    // }
};