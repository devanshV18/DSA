#include<iostream>
#include<bits/stdc++.h>
#include<queue>
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
vector<vector<int>> zigzag(node* root){
    vector<vector<int>> result;

    if(root == NULL){
        return result;
    }

    queue<node*> q;
    q.push(root);
    bool ltr = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);

        for(int i = 0 ; i<size; i++){
            node* frontNode = q.front();
            q.pop();

            int index = (ltr) ? i : size-1-i;
            row[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }

        }

        ltr = !ltr;
        result.push_back(row);
    }

    return result;
}

int main(){
    queue<int> q;
    q.push(1);

    cout<<q.size()<<endl;
    
}