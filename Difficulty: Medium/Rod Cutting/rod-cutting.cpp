// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i] = (i)*price[0];
        }
        for(int ind=1;ind<n;ind++){
            for(int len=0;len<=n;len++){
                int notTake = dp[ind-1][len];
                int take = INT_MIN;
                int rodLen = ind+1;
                if(rodLen<=len){
                    take = price[ind] + dp[ind][len-rodLen];
                }
                dp[ind][len] = max(notTake,take);
            }
        }
        return dp[n-1][n];
    }
};