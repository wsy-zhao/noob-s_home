#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <string>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// defination of a 2-ary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// defination of a N-ary tree
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// postorder traversal of a N-ary tree from the root node, recursion approach
class postorder4N{
public:
    std::vector<int> ans;

    void helper(Node* );
    std::vector<int> postorder(Node* );
};

// preorder traversal of a N-ary tree from the root node, recursion approach
class preorder4N{
public:
    std::vector<int> ans;
    void helper(Node *);
    std::vector<int> preorder(Node *);
};

// print a 1-dim vector
template<typename T> 
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v){
    os << "[ ";
    for (T i : v){
        os << i << " "; 
    }
    os << "]" << std::endl;
    return os;
}

// print a 2-dim vector
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v){
    for (std::vector<T> i : v){
        os << "[ ";
        for (T j : i){
            os << j << " ";
        }
        os << "]" << std::endl;
    }
    return os;
}

void print_list(ListNode * );

std::vector<int> preorderTraversal(TreeNode*);
std::vector<int> postorderTraversal(TreeNode*);
std::vector<int> inorderTraversal(TreeNode*);
void traversal(TreeNode*, int);

std::string multiply(std::string, std::string);

void swap(int*, int*);
void swap(int&, int&);

#endif