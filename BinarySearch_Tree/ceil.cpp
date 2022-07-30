#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findCeil(BinaryTreeNode<int> *root, int key){
        int ceil = -1;
        while(root){
            if(root->data == key){
                ceil = root->data;
                return ceil;
            }
            
            if(key > root->data){
                root = root->right;
            }
            else{
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
    }

    //For Floor
    int findFloor(BinaryTreeNode<int> *root, int key){
        int floor = -1;
        while(root){
            if(root->data == key){
                floor = root->data;
                return floor;
            }
            
            if(key > root->data){
                floor = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return floor;
    }
}
