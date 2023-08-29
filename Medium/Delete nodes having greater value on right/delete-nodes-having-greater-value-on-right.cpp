//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *reverse(Node *head){
        Node *prev = NULL, *curr = head, *n = head->next;
        
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = n;
            if(n != NULL)n = n->next;
        }
        return prev;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        if(head == NULL || head->next == NULL) return head;
        stack<int> st;
        
        Node *curr = head;
        while(curr){
            while(!st.empty() && st.top()<curr->data){
                st.pop();
            }
            st.push(curr->data);
            curr = curr->next;
        }
        
        Node *dummy = new Node(-1);
        Node *tail = dummy;
        
        while(!st.empty()){
            Node *temp = new Node(st.top());
            st.pop();
            tail->next = temp;
            tail = temp;
        }
        
        tail->next = NULL;
        return reverse(dummy->next);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends