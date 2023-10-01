class Solution
{
    public:
    //Function to find the maximum money the thief can get.
     int solve(int arr[] , int n , int i , vector<int>& dp){

        if(i>=n){

            return 0;

        }

        if(dp[i] != -1){

            return dp[i];

        }

        

        int amt1 = arr[i] + solve(arr,n,i+2,dp);

        int amt2 = solve(arr,n,i+1,dp);

        

        dp[i] = max(amt1,amt2);

        return dp[i];

    }

    int FindMaxSum(int arr[], int n)

    {

        vector<int> dp(n,-1);

        return solve(arr,n,0,dp);

    }
};
