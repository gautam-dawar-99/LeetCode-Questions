// problem link : https://leetcode.com/problems/permutations/
class Solution {
public:
    void permutation(vector<int>& arr,int i,int n,vector<vector<int>>& ans){
        
        if(i==n){
            ans.push_back(arr);   //(when i will be length of nums)
        }
        else{
            for(int j=i;j<n;j++){   // traverse from i to n
                swap(arr[i],arr[j]); // swap 
                permutation(arr,i+1,n,ans); // call for next 
                swap(arr[j],arr[i]); // backtracking
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();  // find size of nums int array
        vector<vector<int>> ans; // to store ans as 2d vector
        permutation(nums,0,n,ans); // call funcn as helper
        return ans; // return ans(2d vector)
    }
};


