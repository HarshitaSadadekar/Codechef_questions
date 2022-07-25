#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL){
            return postorder;
        }
        
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left != NULL){
                st1.push(root->left);
            }
            if(root->right != NULL){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        
        return postorder;
    }
};

//Iterative PostOrder using 1 stack
while(curr != NULL || !st.empty){
    if(curr != NULL){
        st.push(curr);
        curr = curr->left;
    }
    else{
        temp = st.top()->right;
        if(temp == NULL){
            temp =st.top();
            st.pop();
            postorder.push_back(temp);
            while(!st.empty() && temp == st.top()->right){
                temp = st.top();
                st.pop();
                postorder.push_back(temp->val);
            }
        }
        else{
            curr=temp;
        }
    }
}