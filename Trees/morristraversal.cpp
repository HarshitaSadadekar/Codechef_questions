#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    vector<int> getInorder(TreeNode* root){
        vector<int> inorder;
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        // find the element in left subtree that will be visited the last
            else{
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                
                if(prev->right ==NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
    return inorder;
    }
}
