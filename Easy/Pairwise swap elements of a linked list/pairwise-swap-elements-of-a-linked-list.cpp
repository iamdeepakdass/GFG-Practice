//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
    void reverse(Node *s, Node *e){
        Node *prev = NULL;
        Node *curr = s;
        Node *nexxt = curr->next;
        
        while(prev != e){
            curr->next = prev;
            prev = curr;
            curr = nexxt;
            if(nexxt != NULL){
                nexxt = nexxt->next;
            }
        }
    }
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node *dummy = new Node(-1);
        dummy->next = head;
        Node *beforeStart = dummy;
        Node *end = head;
        
        int i=0;
        while(end != NULL){
            i++;
            
            if(i%2 == 0){
                Node *s = beforeStart->next;
                Node *temp = end->next;
                reverse(s,end);
                beforeStart->next = end;
                s->next = temp;
                beforeStart = s;
                end = temp;
            }
            else{
                end = end->next;
            }
        }
        
        return dummy->next;
    }
};

//{ Driver Code Starts.

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		map<Node*, int> mp;
		mp[head] = head->data;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
			mp[tail] = tail->data;
		}
		struct Node *failure = new Node(-1);
		Solution ob;
		head = ob.pairWiseSwap(head);
		int flag = 0;
		struct Node *temp = head;
		while(temp){
		    if(mp[temp] != temp->data){
		        flag = 1;
		        break;
		    }
		    temp = temp->next;
		}
		if(flag)
		    printList(failure);
		else
		    printList(head);
	}
	return 0; 
}

// } Driver Code Ends