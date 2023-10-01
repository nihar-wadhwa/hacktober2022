// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(1e5, 1e9);
        int mod = 1e5;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(node == end){
                return steps;
            }
            for(auto it: arr){
                int num = (it* node)%mod;
                if(steps + 1 < dist[num]){
                    q.push({num, steps + 1});
                    dist[num] = steps + 1;
                }
            }
        }
        return -1;
    }
};
