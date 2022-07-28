#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool getPath(TreeNode *root, vector<int> &arr, int x){
        if(!root){
            return false;
        }
        arr.push_back(root->val);

        if(root->val == x){
            return true;
        }

        if(getPath(root->left, arr, x) || getPath(root->right, arr, x)){
            return true;
        }

        arr.pop_back();
        return false;
    }
    
    public:
    vector<int> arr;
    if(A == NULL){
        return arr;
    }
    getPath(A, arr, B);
    return arr;
}