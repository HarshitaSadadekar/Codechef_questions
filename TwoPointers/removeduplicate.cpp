//Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        int i=1,j=1,k=1;
        
        
            while(j< nums.size()){
                if(nums[j] == nums[j-1]){
                    j++;
                }
                else if(nums[j] != nums[j-1]){
                    nums[i]=nums[j];
                    k++;
                    i++; 
                    j++;
                }
            }
        return k;
}

int main(){
    int i,n,c;
    cin>>n;
    vector<int> nums1;
    for(i=0; i<n; i++){
        cin>>c;
        nums1.push_back(c);
    }
    cout<<removeDuplicates(nums1);
    return 0;
}