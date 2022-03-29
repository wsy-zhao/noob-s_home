using namespace std;

class Solution{
public:
    // bool hasAlternatingBits(int n) {
    //     int last = 1 & n;
    //     n >>= 1;
    //     while(n > 0 && (n ^ last) & 1){
    //         last ^= 1;
    //         n >>= 1;
    //     }
    //     return n > 0 ? false : true;
    // }

    bool hasAlternatingBits(int n) {
        long a = n ^ (n >> 1); // if it has alternating bits, `a` combines by 1
        return (a & (a + 1)) == 0; // ensure `a` only combines by 1
    }
};