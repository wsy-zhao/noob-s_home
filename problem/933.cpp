#include "../utils/utils.h"
using namespace std;

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {

    }
    
    int ping(int t) {
        int lowest = t - 3000;
        while (q.front() < lowest){
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};