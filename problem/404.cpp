#include "../utils/utils.h"
// dont travel to the leaves, just travel to their parents
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left != nullptr){
            // find a left leaf
            if(root->left->left == nullptr && root->left->right == nullptr){
                //  it has a right sub-tree
                if (root->right != nullptr){
                    return root->left->val + sumOfLeftLeaves(root->right);
                }
                //  it doesnt has a right sub-tree
                else{
                    return root->left->val;
                }
            }
            // not find a left leaf
            else{
                // weather it has a right sub-tree
                if(root->right!=nullptr){
                    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
                }
                else{
                    return sumOfLeftLeaves(root->left);
                }
            }
        }
        else if (root->right != nullptr){
            return sumOfLeftLeaves(root->right);
        }
        else {
            return 0;
        }
    }
};