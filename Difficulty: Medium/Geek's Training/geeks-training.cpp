class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(4,0));
        int tdays=arr.size();
        dp[0][1]=max(arr[0][0],arr[0][2]);
        dp[0][2]=max(arr[0][0],arr[0][1]);
        dp[0][0]=max(arr[0][1],arr[0][2]);
        dp[0][3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
        
        for(int day=1;day<tdays;day++){
            for(int last=0;last<4;last++){
                dp[day][last]=0;
                for(int task=0;task<3;task++){
                    if(task!=last){
                        int activity=arr[day][task]+dp[day-1][task];
                        dp[day][last]=max(dp[day][last],activity);
                    }
                }
            }
        }
        return dp[n-1][3];
    }
};