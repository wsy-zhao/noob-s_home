#include "../utils/utils.h"
#include <deque>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // judge whether the root node is nullptr
        if (!root){
            return {};
        }
        // initialze the answer, node counter, queue
        vector<vector<int>> ans;
        int node_num_in_layer = 1;
        deque<Node *> queue = {root};
        // travel core
        while (!queue.empty()){
            int node_num_in_next_layer = 0, ans_size = ans.size();
            ans.emplace_back(vector<int>());
            // this layer
            while(node_num_in_layer > 0){
                ans[ans_size].emplace_back(queue.front()->val);
                // next layer
                if(!queue.front()->children.empty()){
                    int num_of_children = queue.front()->children.size();
                    for(int i = 0; i < num_of_children; i++){
                        queue.emplace_back(queue.front()->children[i]);
                        ++node_num_in_next_layer;
                    }
                }
                queue.pop_front();
                node_num_in_layer--;
            }
            node_num_in_layer = node_num_in_next_layer;
        }
        return ans;
    }
};