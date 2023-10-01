//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int i = 1;
        while(n > 0) {
            int bit = n % 2;
            if(bit == 1)
                return i;
            n /= 2;
            i++;
        }
        return 0;
    }
};
