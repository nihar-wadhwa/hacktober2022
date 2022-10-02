#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    static void swap(vector<int> &arr,int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
    }
	int minSwaps(vector<int> &arr){
	    int N=arr.size();
	    int ans = 0;
	    vector<int>temp = arr; map <int, int> h;
 
  sort(temp.begin(), temp.end());
  for (int i = 0; i < N; i++)
  {
    h[arr[i]] = i;
  }
  for (int i = 0; i < N; i++)
  {
      if (arr[i] != temp[i])
    {
      ans++;
      int init = arr[i];
 swap(arr, i, h[temp[i]]);
      h[init] = h[temp[i]];
      h[temp[i]] = i;
    }
  }
  return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
