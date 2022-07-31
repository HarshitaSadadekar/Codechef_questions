#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
        TreeNode* successor = NULL;
        while(root != NULL){
            if(p->val >= root->val){
                successor = root;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return successor;
    }
}