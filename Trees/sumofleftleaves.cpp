#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int solve(TreeNode* root, bool left){
        if(root==NULL){
            return 0;
        }
        if(!root->left && !root->right && left){
            return root->val;
        }
        
        return solve(root->left, true) + solve(root->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false);
    }
};