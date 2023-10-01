
class Solution
{
    public:
    
    long long solve(int n){
        long long dist[3];
        //base cases
        dist[0]=1;
        dist[1]=1;
        dist[2]=2;
        int mod=1e9;
        for(int i=3;i<=n;i++){
            dist[i%3]=(dist[(i-1)%3]+dist[(i-2)%3]+dist[(i-3)%3])%(mod+7);
        }
        return dist[n%3]%(mod+7);
    }
    
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        return solve(n);
        
    }
};
