#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for(int i = 0; i < k; i++){
            available.insert(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> request(k); // server count 
        for (int i = 0; i < arrival.size(); i++){
            // which tasks are over
            while(!busy.empty() && busy.top().first <= arrival[i]){
                available.insert(busy.top().second);
                busy.pop();
            }
            // if no available server, throw task arrival[i]
            if (available.empty()){
                continue;
            }
            // find a available server 
            auto p = available.lower_bound(i % k);
            if (p == available.end()){
                p = available.begin();
            }
            request[*p]++;
            busy.emplace(arrival[i] + load[i], *p);
            available.erase(*p);
        }

        // statistic 
        vector<int> res;
        int maxRequest = *max_element(request.begin(), request.end());
        for(int i=0; i < k; i++){
            if (request[i] == maxRequest){
                res.push_back(i);
            }
        } 
        return res;
    }
};