// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
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
    int findMinDiff(TreeNode* root, int &mindiff, int &val){
        if(root->left != NULL){
            findMinDiff(root->left, mindiff, val);
        }
        if(val >= 0){
            mindiff = min(mindiff, root->val - val);
        }
        
        val = root->val;
        if(root->right){
            findMinDiff(root->right, mindiff, val);
        }
        
        return mindiff;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        auto mindiff = INT_MAX;
        auto val = -1;
        return findMinDiff(root, mindiff, val);
    }
};