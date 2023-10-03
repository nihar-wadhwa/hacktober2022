class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        int row,col;
        if(!isEmpty(grid,row,col)) return true; // no empty cell, sudoku solved
        
        for(int num=1;num<=9;num++){
            if(!isPresent(grid,row,col,num)){
                grid[row][col] = num;
                if(SolveSudoku(grid)) return true;
                grid[row][col] = 0; //if not solvable, backtrack and try next number
            }
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout << grid[i][j] << " ";
            }
        }
    }
    
    private:
    //Function to check if there is a empty cell
    bool isEmpty(int grid[N][N],int& row,int& col){
        for(row=0;row<N;row++){
            for(col=0;col<N;col++){
                if(grid[row][col]==0) return true;
            }
        }
        return false;
    }
    
    //Function to check if a number is present in a row or a col or the 3x3 sub grid
    bool isPresent(int grid[N][N],int row,int col,int num){
        for(int i=0;i<N;i++){
            if(grid[row][i] == num || grid[i][col] == num) return true; //number is present, cannot be used
        }
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[startRow + i][startCol + j] == num) return true;  //number is present, cannot be used
            }
        }
        return false; //number is not present, hence can be used
    }
};
