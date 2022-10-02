#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<vector<int>> ans;
        int n=intervals.size(),t=INT_MIN;
        sort(intervals.begin(),intervals.end());
        //for(auto i:intervals)cout<<i[0]<<" "<<i[1]<<endl;
        for(int i=0;i<n;i++){
            int temp=i,maxi=intervals[i][1];
            while(i+1<n and maxi>=intervals[i+1][0]){
                i++;
                if(intervals[i][1]>maxi)maxi=intervals[i][1];
            }
            if(maxi>t)
                ans.push_back({intervals[temp][0],maxi});
            t=ans.back()[1];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
