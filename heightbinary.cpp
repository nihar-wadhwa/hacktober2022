
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
         int x,y;
   if(node!=NULL){
       x= height(node->left);
       y= height(node->right);
       return x>y ? x+1:y+1;
   }
   return 0;
}
};
