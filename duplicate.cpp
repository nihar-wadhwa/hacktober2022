vector<int> duplicates(long long arr[], int n) {
        // code here
        vector<int>v;
        map<int,int>hash;
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }
        for(auto i : hash){
            if(i.second>1){
                v.push_back(i.first);
            }
        }
        if(v.size()==0){
            v.push_back(-1);
            return v;
        }
        return v;
    }
