class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // Sort the input arrays in descending order.
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int sum = A[i] + B[j];

                if (pq.size() < K || sum > pq.top()) {
                    pq.push(sum);

                    // If the size exceeds K, pop the smallest element.
                    if (pq.size() > K) {
                        pq.pop();
                    }
                } else {
                    // Since the arrays are sorted in descending order, if A[i]+B[j] <= pq.top(),
                    // further elements in B won't yield a larger sum, so break the inner loop.
                    break;
                }
            }
        }

        vector<int> ans;

        // Transfer elements from the priority queue to the result vector.
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        // Reverse the result vector to get the elements in descending order.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
