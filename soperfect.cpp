class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        long long sum = 0;
        if (N == 1){
            return 0;
        }
        for (int i=1; i<=sqrt(N); i++){
            if (N%i==0){
                sum += i;
            }
            if (N%i == 0 && N/i != N){
                sum+=N/i;
            }
        }
        if (sum == N){
            return 1;
        }
        return 0;
    }
};
