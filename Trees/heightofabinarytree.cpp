#include<iostream>
using namespace std;


class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

int height(node* root){
    //base case
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left,right)+1;

    return ans;
}

// void inorder(node* root){
//     //base case
//     if(root == NULL){
//         return;
//     }

//     inorder(root -> left);
//     cout << root -> data << endl;
//     inorder(root -> right);
// }

// void inorderForLeafs(node* root, int &count){
//     //base case
//     if(root == NULL){
//         return;
//     }

//     inorderForLeafs(root -> left,count);

//     if(root->left == NULL && root->right == NULL){
//         count++;
//     }
//     inorderForLeafs(root -> right,count);
// }

// int noOfLeafNodes(node* root){
//     int cnt=0;
//     inorderForLeafs(root,cnt);
//     return cnt;
// }


int main(){
    node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    


}