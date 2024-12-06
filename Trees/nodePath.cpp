#include <iostream> 
#include<vector>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

bool rootTONodePath(TreeNode* root, int x, vector<int> &path){

    if(root == NULL){
        return false;
    }

    path.push_back(root->data);


    if(root->data == x){
        return true;
    }

    bool leftPath = rootTONodePath(root->left,x, path);
    bool rightPath = rootTONodePath(root->right,x, path);

    if(leftPath || rightPath){
       return true;
    }
    
    path.pop_back();
    return false;
}


int main() {
    // Construct a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(3);

    vector<int> path;
    int target = 7;

    if (rootTONodePath(root, target, path)) {
        cout << "Path to node " << target << ": ";
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        cout << "Node " << target << " not found in the tree." << endl;
    }

    return 0;
}