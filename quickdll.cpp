

/*
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};
*/
class Solution{
public:
    Node* partition(Node *l, Node *h)
   {
       Node *temp = h;
       Node *tt = l;
       Node *first = l;
       while(tt!=h)
       {
           if(tt->data <= temp->data)
           {
               swap(first->data,tt->data);
               first = first->next;
           }
           tt = tt->next;
       }
       swap(first->data,h->data);
       return first;
   }
};
