//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node *&head){
        Node *prev = NULL, *curr = head, *n = curr->next;
        
        while(curr != NULL){
            curr->next = prev;
            prev = curr;
            curr = n;
            if(n != NULL){
                n = n->next;
            }
        }
        
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        Node *slow = head, *fast = head;
        // get the mid point of the list
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                break;
            }
        }
        
        // reverse half of the list
        Node *ptr1 = reverse(slow->next);
        Node *ptr2 = head;
        
        // now check data of each node if they are same
        while(ptr1 != NULL){
            if(ptr1->data != ptr2->data){
                return false;
            }
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
        }
        
        // reverse the half of the list least again in order to make it same again
        slow->next = reverse(slow->next);
        return true;
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends