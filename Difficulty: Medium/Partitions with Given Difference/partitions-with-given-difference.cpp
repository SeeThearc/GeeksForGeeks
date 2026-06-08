class Solution {
  public:
    int find(int ind,int tar,vector<int>&arr,vector<vector<int>>&dp){
        if(tar<0)return 0;
        if(ind==0){
            if(tar==0 && arr[ind]==tar)return 2;
            if(tar==0 || arr[ind]==tar)return 1;
            return 0;
        }
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        int notpick = find(ind-1,tar,arr,dp);
        int pick = find(ind-1,tar-arr[ind],arr,dp);
        return dp[ind][tar] = pick + notpick;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int total=0;
        for(int x:arr)total+=x;
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        if(total<diff)return 0;
        if((total+diff) %2==1)return 0;
        int ans = find(n-1,(diff+total)/2,arr,dp);
        return ans;
    }
};