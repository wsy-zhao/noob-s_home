#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    // 深度优先搜索 + 归并
    // void preOrderTravel(TreeNode* root, vector<int> &result){
    //     if (root == nullptr){
    //         return ;
    //     }
    //     preOrderTravel(root->left, result);
    //     result.emplace_back(root->val);
    //     preOrderTravel(root->right, result);
    // }

    // 使用了三个数组
    // vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    //     vector<int> result1, result2;
    //     preOrderTravel(root1, result1);
    //     preOrderTravel(root2, result2);
    //     vector<int> result;
    //     int size1 = result1.size(), size2 = result2.size();
    //     int i = 0, j = 0;
    //     while(i < size1 && j < size2){
    //         if(result1[i] < result2[j]){
    //             result.emplace_back(result1[i++]);
    //         }
    //         else{
    //             result.emplace_back(result2[j++]);
    //         }
    //     }
    //     while(i < size1){
    //         result.emplace_back(result1[i++]);
    //     }
    //     while (j < size2){
    //         result.emplace_back(result2[j++]);
    //     }
    //     return result;
    // }

    // 只使用了两个数组， 时间反而更长了，insert比较耗时间
    // vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    //     vector<int> result1, result2;
    //     preOrderTravel(root1, result1);
    //     preOrderTravel(root2, result2);
    //     int size1 = result1.size(), size2 = result2.size();
    //     int i = 0, j = 0;
    //     while(i < size1 && j < size2){
    //         if(result2[j] < result1[i]){
    //             result1.insert(result1.begin() + i, result2[j++]);
    //             ++size1;
    //         }
    //         ++i;
    //     }
    //     while (j < size2){
    //         result1.emplace_back(result2[j++]);
    //     }
    //     return result1;
    // }

    // 两棵树同时遍历
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
        stack<TreeNode *> st_rt1, st_rt2;
        vector<int> result;
        TreeNode* head1 = root1, *head2 = root2; 
        while (head1 != nullptr){
            st_rt1.push(head1);
            head1 = head1->left;
        }
        while (head2 != nullptr){
            st_rt2.push(head2);
            head2 = head2->left;
        }
        while(!st_rt1.empty() && !st_rt2.empty()){
            TreeNode * top1 = st_rt1.top(), *top2 = st_rt2.top();
            if(top1->val > top2->val){
                result.emplace_back(top2->val);
                st_rt2.pop();
                if (top2->right != nullptr){
                    st_rt2.push(top2->right);
                    top2 = top2->right;
                    while (top2->left != nullptr){
                        st_rt2.push(top2->left);
                        top2 = top2->left;
                    }
                } 
            }
            else{
                result.emplace_back(top1->val);
                st_rt1.pop();
                if (top1->right != nullptr){
                    st_rt1.push(top1->right);
                    top1 = top1->right;
                    while (top1->left != nullptr){
                        st_rt1.push(top1->left);
                        top1 = top1->left;
                    }
                } 
            }
        }
        while(!st_rt1.empty()){
            TreeNode * top1 = st_rt1.top();
            result.emplace_back(top1->val);
            st_rt1.pop();
            if (top1->right != nullptr){
                st_rt1.push(top1->right);
                top1 = top1->right;
                while (top1->left != nullptr){
                    st_rt1.push(top1->left);
                    top1 = top1->left;
                }
            } 
        }
        while(!st_rt2.empty()){
            TreeNode * top2 = st_rt2.top();
            result.emplace_back(top2->val);
            st_rt2.pop();
            if (top2->right != nullptr){
                st_rt2.push(top2->right);
                top2 = top2->right;
                while (top2->left != nullptr){
                    st_rt2.push(top2->left);
                    top2 = top2->left;
                }
            } 
        }
        return result;
    }
};