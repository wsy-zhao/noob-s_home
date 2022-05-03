#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
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


// Definition for a QuadTree node.
class QuadNode {
public:
    bool val;
    bool isLeaf;
    QuadNode* topLeft;
    QuadNode* topRight;
    QuadNode* bottomLeft;
    QuadNode* bottomRight;
    
    QuadNode() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    QuadNode(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    QuadNode(bool _val, bool _isLeaf, QuadNode* _topLeft, QuadNode* _topRight, QuadNode* _bottomLeft, QuadNode* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
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

// write a 1-dim vector into ostream 
// 并不严谨， 如果`T`是一个容器呢 
template<typename T> 
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v){
    os << "[ ";
    for (T i : v){
        os << i << " "; 
    }
    os << "]";
    return os;
}

// write a 2-dim vector into ostream
// another version, more interesting !!!! 
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v){
    size_t size_v = v.size();
    for (int i = 0; i < size_v; ){
        os << v[i] << (++i == size_v ? "" : "\n");
    }
    return os;
}

/* write a 2-dim vector into ostream
 * previous version
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v){
    size_t size_v = v.size();
    for (int i = 0; i < size_v; ){
        os << "[ ";
        for (T j : v[i]){
            os << j << " ";
        }
        os << "]" << (++i == size_v ? "" : "\n");
    }
    return os;
}
*/

void print_list(ListNode * );

std::vector<int> preorderTraversal(TreeNode*);
std::vector<int> postorderTraversal(TreeNode*);
std::vector<int> inorderTraversal(TreeNode*);
void traversal(TreeNode*, int);

std::string multiply(std::string, std::string);

void swap(int*, int*);
void swap(int&, int&);

// write a LinkedList into ostream
std::ostream &operator<<(std::ostream &, ListNode *);

class DisjointSetUnion{
private:
    std::vector<int> parent, rank;

public:
    DisjointSetUnion(int);
    int find(int);
    bool construct(int, int);
};

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {
    }
};

int kruskal(std::vector<std::vector<int>> &);
#endif