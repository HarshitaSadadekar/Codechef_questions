// Minimum time taken to burn the entire binary tree from a given node or leaf node

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findMaxDist(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mp, BinaryTreeNode<int>* target){
        queue<BinaryTreeNode<int>*> q;
        q.push(target);
        map<BinaryTreeNode<int>*, int> vis;
        vis[target] = 1;
        int maxi = 0;

        while(!q.empty()){
            int size = q.size();
            int fl=0; //flag

            for(int i=0; i<size; i++){
                auto node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    fl=1;
                    vis[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    fl=1;
                    vis[node->right]=1;
                    q.push(node->right);
                }
                if(mp[node] && !vis[mp[node]]){ // for parent 
                    fl=1;
                    vis[mp[node]]=1;
                    q.push(mp[node]);
                }
            }
            if(fl){
                maxi++; //flag=1 means I have burned someone next to me so Ill do maxi++
            }
        }
        return maxi;
    }

    BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mp, int start){
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        BinaryTreeNode<int>* res;

        while(!q.empty()){
            BinaryTreeNode<int>* node = q.front();
            if(node->data == start){
                res = node;
            }
            q.pop();

            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

    int timeToBurnTree(BinaryTreeNode<int>* root, int start){
        map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mp;
        BinaryTreeNode<int>* target = bfsToMapParents(root, mp, start);
        int maxi = findMaxDist(mp, target);
        return maxi;
    }
}