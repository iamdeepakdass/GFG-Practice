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
    void reverseLL(Node *s, Node *e){
        Node *prev = NULL, *n = s->next, *curr = s;
        
        while(prev != e){
            curr->next = prev;
            prev = curr;
            curr = n;
            if(n != NULL) n = n->next;
        }
    }

    Node *compute(Node *head)
    {
        // your code goes here
        if(head == NULL || head->next == NULL) return head;
        
        Node *curr = head;
        stack<int> st;
        
        while(curr != NULL){
            while(!st.empty() && st.top() < curr->data){
                st.pop();
            }
            
            st.push(curr->data);
            curr = curr->next;
        }
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        
        while(!st.empty()){
            Node *newNode = new Node(st.top());
            temp->next = newNode;
            temp = newNode;
            st.pop();
        }
        curr = dummy->next;
        while(curr->next != NULL){
            curr = curr->next;
        }
        
        Node *s = dummy->next;
        reverseLL(s,curr);
        dummy->next = curr;
        s->next = NULL;
        
        return dummy->next;
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