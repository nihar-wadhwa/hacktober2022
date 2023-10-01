//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int i = 0, j = m - 1;
        int a = arr[0], b = brr[m - 1];
        int dist = INT_MAX;
    
        while (i < n && j >= 0) {
            int sum = arr[i] + brr[j];
            int currDist = abs(x - sum);
    
            if (currDist < dist) {
                dist = currDist;
                a = arr[i];
                b = brr[j];
            }
    
            if (sum > x)    j--;
            
            else  i++;
        }
    
        return {a, b};
    }
};
