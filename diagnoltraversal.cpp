

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
    vector<int>ans;
   queue<Node*>q;
   
   
   q.push(root);
   while(q.size()>0)
   {
       Node* t=q.front();
       q.pop();
      
       while(t!=NULL)
       {
           ans.push_back(t->data);
                if(t->left)
                    q.push(t->left);
              
         
           t=t->right;
       }
   }
   return ans;
}
