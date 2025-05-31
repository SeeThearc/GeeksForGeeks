class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int hash[n+1] = {0};
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }
        int missing,repeat;
        for(int i=1;i<=n;i++){
            if(hash[i]>1){
                repeat=i;
            }
            else if(hash[i]==0){
                missing=i;
            }
        }
        vector<int>temp = {repeat,missing};
        return temp;
    }
};