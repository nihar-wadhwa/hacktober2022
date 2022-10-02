
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        map<int,int> top;
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            q.pop();
            Node* temp1=temp.first;
            int hd=temp.second;
            top[hd]=temp1->data;
            if(temp1->left)q.push(make_pair(temp1->left,hd-1));
            if(temp1->right)q.push(make_pair(temp1->right,hd+1));
        }
        for(auto i:top)ans.push_back(i.second);
        return ans;
    }
};
