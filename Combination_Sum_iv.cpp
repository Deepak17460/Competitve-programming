class Solution {
    public:
int HelperMem(int n,vector<int>&arr,int k,vector<int>&dp){
    // Base case
      if(k==0) return 1;
      if(k<0) return 0;
    if(dp[k]!=-1) return dp[k];
    int ans=0;
    for(int i=0;i<n;i++){
        if(k>=arr[i])
        ans+=HelperMem(n,arr,k-arr[i],dp);
    }
    return dp[k]=ans;
   
}
int HelperTab(vector<int>& nums,int target){
            int n=nums.size();
    vector<int>dp(target+1,0);
    dp[0]=1;
    for(int i=1;i<=target;i++){
        for(int j=0;j<n;j++){
            // corner case
            if(i-nums[j]>=0)
            dp[i]+=dp[i-nums[j]];
        }
    }
    return dp[target];
    }
    
int combinationSum4(vector<int>& nums, int target) {
        
    //return HelperTab(nums,target);
    vector<int>dp(target+1,-1);
    int n=nums.size();
    return HelperMem(n,nums,target,dp);
    }
};
