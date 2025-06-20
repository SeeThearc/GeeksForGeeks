// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        for(int i=0;i<=capacity;i++){
            dp[0][i]=(i/wt[0])*val[0];
        }
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=capacity;tar++){
                int notTake = dp[ind-1][tar];
                int take = INT_MIN;
                if(wt[ind]<=tar){
                    take = val[ind] + dp[ind][tar-wt[ind]];
                }
                dp[ind][tar] = max(notTake,take);
            }
        }
        return dp[n-1][capacity];
    }
};