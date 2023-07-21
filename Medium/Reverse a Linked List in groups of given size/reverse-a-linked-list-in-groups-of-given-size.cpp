//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    void reverseLL(node *s, node *e){
        node *prev = NULL, *n = s->next, *curr = s;
        
        while(prev != e){
            curr->next = prev;
            prev = curr;
            curr = n;
            if(n != NULL) n = n->next;
        }
        
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        // if the head is NULL or k = 1 then return head 
        if(head == NULL || head->next == NULL || k == 1) return head;
        
        int cnt = 0;
        
        node *dummy = new node(-1);
        dummy->next = head;
        node *beforeStart = dummy;
        node *beforeEnd = NULL;
        node *end = head;

        while(end != NULL){
            cnt++;
            if(cnt % k == 0){
                node *endNext = end->next;
                node *s = beforeStart->next;
                reverseLL(s,end);
                beforeStart->next = end;
                s->next = endNext;
                beforeStart = s;
                end = endNext;
            }
            else{
                beforeEnd = end;
                end = end->next;
            }
        }
        
        if(cnt % k != 0){
            reverseLL(beforeStart->next, beforeEnd);
            beforeStart->next = beforeEnd;
        }
        
        return dummy->next;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends