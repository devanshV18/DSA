#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<unordered_map>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

vector<int> topView(TreeNode* root){
    vector<int> res;

    if(root==NULL){
        return res;
    }

    queue<pair<TreeNode*, int>> q;
    unordered_map<int, int> m;

    q.push({root,0}); //initial push

    while(!q.empty()){
        auto it = q.front(); //destructuring first elemetn of queue using an auto iterator
        q.pop();

        TreeNode* node = it.first; //destructuring the node
        int line = it.second; //destructuring the line

        //only placing , line,node pair for first occurence of each line.
        if(m.find(line) == m.end()){
            m[line] = node->data;
        }

        //performing LOT

        if(node->left){
            q.push({node->left, line-1});
        }

        if(node->right){
            q.push({node->right, line+1});
        } 
    }

    vector<pair<int, int>> sorted(m.begin(), m.end()); // the accumulated map elements in line,node->data pair is stored in a vector of pair
    sort(sorted.begin(), sorted.end()); //sort this vector using lexographic sorting of vector.

    for( auto it : sorted ){
        res.push_back(it.second);
    }

    return res;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    // Get the top view
    vector<int> topViewResult = topView(root);

    // Print the result
    cout << "Top view of the tree: ";
    for (int i : topViewResult) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}