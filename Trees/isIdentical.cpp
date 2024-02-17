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

    int left = height(root -> left);
    int right = height(root -> right);
    int ans = max(left,right) + 1;

    return ans;
}

bool isIdentical(node* r1, node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }

    if(r1==NULL && r2!=NULL){
        return false;
    }

    if(r1!=NULL && r2==NULL){
        return false;
    }

    bool left = isIdentical(root -> left);
    bool right = isIdentical(root -> right);

    bool curr = r1->data == r2->data;

    if(left && right && curr){
        return true;
    }

    else{
        return false;
    }
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    


}