#include<bits/stdc++.h>
using namespace std;

class Solution{
    void addLeftBoundary(Node* root, vector<int> &res){
        Node* cur = root->left;

        while(cur){
            if(!isLeaf(cur)){
                res.push_back(cur->data); // if not a leaf node then push
            }
            if(cur->left){
                cur = cur->left; //keep going to left
            }
            else{
                cur = cur->right; //if no left then right
            }
        }
    }

    void addRightBoundary(Node* root, vector<int> &res){
        Node* cur = root->right;
        vector<int> temp;

        while(cur){
            if(!isLeaf(cur)){
                temp.push_back(cur->data); // if not a leaf node then push
            }
            if(cur->right){
                cur = cur->right; // keep going to right
            }
            else{
                cur = cur->left; // if not right then left
            }
        }
        for(int i=temp.size(); i>=0; i--){
            res.push_back(temp[i]);
        }
    }

    void addLeaves(Node* root, vector<int> &res){
        if(!isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left){
            addLeaves(root->left, res);        
        }
        if{
            addLeaves(root->right, res);
        }
    }
}

    public:
    vector<int> printBoundary(Node* root){
        vector<int> res;
        if(!root){
            return res;
        }
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
}