#include "utils.h"

using namespace std;

// preorder traversal of a 2-ary tree from the root node, recursion approach
vector<int> preorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        vector<int> res = { root->val };
        vector<int> left = preorderTraversal(root->left);
        res.insert(res.end(), left.begin(), left.end());
        vector<int> right = preorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
    else {
        return {};
    }
}

// postorder traversal of a 2-ary tree from the root node, recursion approach
vector<int> postorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        vector<int> res = { root->val };
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        res.insert(res.begin(), right.begin(), right.end());
        res.insert(res.begin(), left.begin(), left.end());
        return res;;
    }
    else {
        return {};
    }
}

// inorder traversal of a 2-ary tree from the root node, recursion approach
vector<int> inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        vector<int> res = { root->val };
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        res.insert(res.begin(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
    else {
        return {};
    }
}

// traversal a tree by your choose
void traversal(TreeNode* root, int method) {
    vector<int> res;
    switch (method) {
    case -1:
        cout << "Postorder" << endl;
        res = postorderTraversal(root); 
        break;
    case 0:
        cout << "Inorder" << endl;
        res = inorderTraversal(root); 
        break;
    case 1:
        cout << "Preorder" << endl;
        res = preorderTraversal(root);
        break;
    default:
        cout << "Method not exit" << endl;
        break;
    }
   //  print_vector(res);
    cout << "Traversal Over" << endl;

}

// postorder traversal of a N-ary tree from the root node, recursion approach
void postorder4N::helper(Node* root) {
    if (root != nullptr) {
        for (auto r : root->children) {
            helper(r);
        }
        ans.push_back(root->val);
    }
}

vector<int> postorder4N::postorder(Node* root){
    helper(root);
    return ans;
}

// preorder traversal of a N-ary tree from the root node, recursion approach
void preorder4N::helper(Node *root){
        if (root != nullptr) {
        ans.push_back(root->val);
        for (auto r : root->children) {
            helper(r);
        }
    }
}

vector<int> preorder4N::preorder(Node* root) {
    helper(root);
    return ans;
}

// multiply two number representing by `string`
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    string ans = "";
    int base = 0;
    for (int i = num2.size() - 1; i >= 0; i--) {
        string tmp_ans = "";
        int carry_m = 0, carry_p = 0, len_ans = ans.size();
        for (int j = num1.size() - 1; j >= 0; j--) {
            // multiply 
            int bit = (num1[j] - '0') * (num2[i] - '0') + carry_m;
            carry_m = bit / 10;
            bit -= carry_m * 10;
            tmp_ans = to_string(bit) + tmp_ans;
        }
        if (carry_m) {
            tmp_ans = to_string(carry_m) + tmp_ans;
        }
         // add
        int len_ta = tmp_ans.size();
        for (int k = 0; k < len_ta; k++) {
            if (len_ans - base - k - 1 >= 0) {
                int bit = ans[len_ans - base - k - 1] + tmp_ans[len_ta - k - 1] - '0' * 2 + carry_p;
                carry_p = bit / 10;
                bit -= carry_p * 10;
                ans[len_ans - base - k - 1] = bit + '0';
            }
            else {
                int bit = tmp_ans[len_ta - k - 1] - '0' + carry_p;
                carry_p = bit / 10;
                bit -= carry_p * 10;
                ans = to_string(bit) + ans;
            }
        }
        if (carry_p) {
            ans = to_string(carry_p) + ans;
        }
        base++;
    }
    return ans;
}

// swap by inference
void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// swap by pointer
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

ostream &operator<<(ostream &os, ListNode *head){
    while (head){
        os << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    return os;
}

DisjointSetUnion::DisjointSetUnion(int n) {
    this->parent = vector<int>(n, -1);
    // this->rank = vector<int>(n, 1);
}

int DisjointSetUnion::find(int x){
    return this->parent[x] == -1 ? x : find(this->parent[x]); 
}

bool DisjointSetUnion::construct(int x, int y){
    int parent_x = this->find(x), parent_y = this->find(y);
    if (parent_x == parent_y){
        return false;
    }
    this->parent[parent_y] = parent_x;
    return true;
}

// kruskal algorithm
int kruskal(vector<vector<int>> & points){
    // define the distance function
    auto dist = [&points](int i, int j) -> int {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    };
    // count of points
    int n = points.size();
    // set of edges
    vector<Edge> edges;
    // initialize edges
    for (int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            edges.emplace_back(dist(i, j), i, j);
        }
    }
    // sort the edges by weight
    sort(edges.begin(), edges.end(), [](const Edge &e1, const Edge &e2) ->bool { return e1.len < e2.len; });
    int ret = 0, num = 1;
    // disjoint set union
    DisjointSetUnion dsu(n);
    // kruskal core
    for (Edge &e : edges){
        if (dsu.construct(e.x, e.y)){
            ret += e.len;
            num++;
            if (num == n){
                break;
            }
        }
    }
    return ret;
}