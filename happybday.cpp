// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& arr, int n, int k) {
        long long lo = 1, hi = 0, ans = 0;
        for(int &e: arr) hi += e;
        if(k == 0) return hi;
        
        while(lo <= hi) {
            long long mid = (lo+hi)/2;
            long long ok = func(mid, arr, n, k);
            if(ok) {
                lo = mid+1;
                ans = max(ans, ok);
            }
            else hi = mid-1;
        }
        return ans;
    }
    long long func(long long val, vector<int> &arr, int n, int k) {
        long long mi = LLONG_MAX, sum = 0, cur = 0;
        for(int i = 0; i < n; i++) {
            if(sum < val) sum += arr[i];
            else {
                mi = min(mi, sum);
                sum = arr[i], cur++;
                if(cur == k) {
                    for(i++; i < n; i++) sum += arr[i];
                    if(sum >= val) {
                        mi = min(mi, sum);
                        sum = arr[i], cur++;
                    }
                }
            }
        }
        if(cur < k+1) return 0;
        return mi;
    }
};
