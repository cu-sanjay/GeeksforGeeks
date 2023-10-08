//{ Driver Code Starts
//

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


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        
        struct Node* node=new Node(data);
        
        // if no node was present initially
        if(head==NULL)
        {
            return node;
        }
        
        // if only one node was present initially
        if(head->next==NULL)
        {
            if(node->data < head->data)
            {
                node->next=head;
                return node;
            }
            else
            {
                head->next=node;
                return head;
            }
        }
        
        
        struct Node* curr=head;                     // on current node
        struct Node* ptr=head->next;                // on next node
        
        
        while(ptr!=NULL)
        {
            // if the data to be inserted is the smallest  
            if(node->data < curr->data)
            {
                node->next=curr;
                return node;
            }
            
            // if data is to be inserted in the middle of the linked list
            if(node->data < ptr->data)
            {
                curr->next=node;
                node->next=ptr;
                return head;
            }
            
            curr=curr->next;
            ptr=ptr->next;
        }
        
        // if data is to be inserted at the end of the linked list
        curr->next=node;
        
        return head;
    }
};


//{ Driver Code Starts.
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
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends