#include <vector>
#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    vector<string> ans;

    void helper(TreeNode* root, string route){
        if (root == nullptr) {
            return ;
        }
        if (root->left == nullptr && root->right == nullptr){
            ans.emplace_back(route + "->" + to_string(root->val));
        }
        helper(root->left, route + "->" + to_string(root->val));
        helper(root->right, route + "->" + to_string(root->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return ans;
        }
        if (root->left == nullptr && root->right == nullptr){
            ans.emplace_back(to_string(root->val));
            return ans;
        }
        helper(root->left, to_string(root->val));
        helper(root->right, to_string(root->val));
        return ans;
    }
};