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
        node *prev = NULL;
        node *curr = s;
        node *nexxt = curr->next;
        
        while(prev != e){
            curr->next = prev;
            prev = curr;
            curr = nexxt;
            if(nexxt != NULL){
                nexxt = nexxt->next;
            }
        }
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head == NULL || head->next == NULL || k == 1){
            return head;
        }
        
        node *dummy = new node(-1);
        dummy->next = head;
        node *beforeStart = dummy;
        node *end = head;
        node *beforeEnd = NULL;
        int cnt = 0;
        node *start = NULL;
        
        while(end != NULL){
            cnt++;
            if(cnt%k == 0){
                node *s = beforeStart->next;
                node *temp = end->next;
                reverseLL(s,end);
                
                beforeStart->next = end;
                s->next = temp;
                //start = s->next;
                beforeStart = s;
                end = temp;
                start = end;
            }
            else{
                beforeEnd = end;
                end = end->next;
            }
        }
        //cout<<beforeEnd->data<<" end data\n";
        if(cnt%k != 0){
            reverseLL(beforeStart->next, beforeEnd);
            beforeStart->next = beforeEnd;
            //beforeEnd->next = NULL;
        }
        //cout<<beforeStart->next->data<<" data\n";
        
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