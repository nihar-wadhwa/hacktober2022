//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here    
        if(n==0)return 0;
        if(n==1)return 1;
        if(n%2!=0)return 0;
        if(n/2==1)return 1;
        else isPowerofTwo(n/2);
        
    }
};
