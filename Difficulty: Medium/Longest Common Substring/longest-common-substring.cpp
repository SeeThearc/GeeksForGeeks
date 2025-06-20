class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n1=s1.size();
        int n2=s2.size();
        int ans=0;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){
                if(s1[ind1-1]==s2[ind2-1]){
                    int val=1+dp[ind1-1][ind2-1];
                    ans=max(ans,val);
                    dp[ind1][ind2]=val;
                }
            }
        }
        return ans;
    }
};