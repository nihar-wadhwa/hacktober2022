// User function Template for C++

class Solution{
public:
    bool solve(int i,int N, int arr[], int sum, vector<vector<int>>&dp){
        if(i>=N) return false;
        if(sum==0) return true;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int nt = solve(i+1,N,arr,sum,dp);
        int t = false;
        if(arr[i]<=sum) t = solve(i+1,N,arr,sum-arr[i],dp);
        
        return dp[i][sum] = (nt || t);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int tot = 0, sum;
        for(int i=0;i<N;i++) tot += arr[i];
        if(tot%2 != 0) return 0;
        sum = tot/2;
        vector<vector<int>>dp(N+1, vector<int>(sum+1,-1));
        return solve(0, N, arr, sum,dp);
    }
};
