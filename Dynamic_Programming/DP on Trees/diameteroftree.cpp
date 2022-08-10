#include<bits/stdc++.h>
using namespace std;

int solve(TreeNode* root, int &res){
    if(root == NULL){
        return 0;
    }

    int lh = solve(root->left, res);
    int rh = solve(root->right, res);
    int temp = 1+max(lh,rh);
    int ans = max(temp, 1+lh+rh);
    res = max(res,ans);

    return temp;
}

int main(){
    int res=INT_MIN;
    solve(root, res);
    cout<<res;
    return 0;
}