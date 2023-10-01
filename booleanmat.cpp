void booleanMatrix(vector<vector<int> > &matrix)
    {
        vector<pair<int,int>>v;
        set<int>p1;
        set<int>p2;
        pair<int,int>p;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==1)
                {
                    p1.insert(i);
                    p2.insert(j);
                }
            }
        }
        for(auto i:p1)
        {
            for(int x=0;x<matrix[0].size();x++)
            {
                
                matrix[i][x]=1;
            }
        }
        for(auto i:p2)
        {
            for(int x=0;x<matrix.size();x++)
            {
                matrix[x][i]=1;
            }
        }
    }
