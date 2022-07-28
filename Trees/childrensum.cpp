#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void changeTree(BinaryTreeNode<int>* root){
        if(root == NULL){
            return;
        }

        int child=0;
        if(root->left){
            child +=root->left->data;
        }
        if(root->right){
            child +=root->right->data;
        }

        if(child >= root->data){
            root->data = child;
        }
        else{
            if(root->left){
                root->left->data = root->data;
            }
            else if(root->right){
                root->right->data = root->data;
            }
        }

        reorder(root->left);
        reorder(root->right);

        int total=0;
        if(root->left){
            total +=root->left->data;
        }
        if(root->right){
            total +=root->right->data;
        }
        if(root->left or root->right){
            root->data = total;
        }
    }
}