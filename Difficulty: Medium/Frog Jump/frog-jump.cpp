class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=0;
        int prev1,prev2;
        for(int i=2;i<=n;i++){
            prev1=abs(height[i-1]-height[i-2])+dp[i-1];
            if(i>=3){
                prev2=abs(height[i-1]-height[i-3])+dp[i-2];
                dp[i]=min(prev1,prev2);
            }
            else{
                dp[i]=prev1;
            }
        }
        return dp[n];
    }
};