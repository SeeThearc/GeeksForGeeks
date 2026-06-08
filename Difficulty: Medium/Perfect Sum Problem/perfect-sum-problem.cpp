class Solution {
  public:
    int find(int ind,int k,vector<int>&nums,vector<vector<int>>&dp){
        if(k<0)return 0;
        if(ind==0){
            if(k==0 && k==nums[ind])return 2;
            if(k==0 || k==nums[ind])return 1;
            return 0;
        }
        if(dp[ind][k]!=-1)return dp[ind][k];
        int notpick = find(ind-1,k,nums,dp);
        int pick = find(ind-1,k-nums[ind],nums,dp);
        return dp[ind][k] = pick+notpick;
    }
    int perfectSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return find(n-1,k,nums,dp);
    }
};