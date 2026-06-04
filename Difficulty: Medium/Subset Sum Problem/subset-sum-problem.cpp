class Solution {
  public:
    bool find(int ind,vector<int>&arr,int sum,vector<vector<int>>&dp){
        if(sum<0)return false;
        if(sum==0)return true;
        if(ind==0)return arr[ind]==sum;
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        bool pick = find(ind-1,arr,sum-arr[ind],dp);
        bool notpick = find(ind-1,arr,sum,dp);
        return dp[ind][sum] = (pick||notpick);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return find(n-1,arr,sum,dp);
    }
};