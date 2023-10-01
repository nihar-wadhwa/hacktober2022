
class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
         vector<int> v;
          int row_i = 0;
          int row_f = n-1;
          int col_i = 0;
          int col_f = m-1;
          
          if(n == 1){
              for(int i=0; i<m; i++){
                  v.push_back(matrix[0][i]);
              }
              return v;
          }
          
          if(m == 1){
              for(int i=0; i<n; i++){
                  v.push_back(matrix[i][0]);
              }
              return v;
          }
          
          for(int i=0; i<m; i++){
              v.push_back(matrix[row_i][i]);
          }
          row_i++; 
          
          for(int i=row_i; i<n; i++){
              v.push_back(matrix[i][col_f]);
          }
          col_f--;
          
          for(int i=col_f; i>=0; i--){
              v.push_back(matrix[n-1][i]);
          }
          row_f--;
          
          for(int i=row_f; i>=row_i; i--){
              v.push_back(matrix[i][col_i]);
          }
          
          return v;
    }
};
