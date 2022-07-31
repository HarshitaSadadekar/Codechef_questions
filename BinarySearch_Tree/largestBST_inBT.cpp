#include<bits/stdc++.h>
using namespace std;

class NodeValue{
public:
    int maxNode,minNode,maxSize;

    NodeValue(int minNode, int maxNode, int maxSize){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution{
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root){
        //an empty tree is a bst of size 0
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        //Get values from left and right subtree of current tree
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        //current node is greater than max in left and smaller than min in right, it is a BST 
        if(left.maxNode < root->val && root->val < right.minNode){
            //It is a BST
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize+1);
        }

        //otherwise return [-inf, inf] so that parent cant be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    public:
        int largestBSTSubtree(TreeNode* root){
            return largestBSTSubtreeHelper(root).maxSize;
        }
}