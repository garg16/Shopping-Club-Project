#include <bits/stdc++.h> 
using namespace std; 
 
// Implemented with the help of stack using Linked List with Nodes.
// Each Node will contain data(cart's number) and next Node's address.

struct bucket
{ 
   int data; 
   bucket* next; 
};
    
struct bucket* top; 
 
void push(int data) 
{  
	struct bucket* temp; 
	temp = new bucket(); 

	if (!temp) 
    { 
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tHeap Overflow"; 
		exit(1); 
	} 

	temp->data = data; 
	temp->next = top; 
	top = temp; 
} 
 
int isEmpty() 
{ 
	return top == NULL; 
} 

void bpop() 
{ 
	struct bucket* temp; 
	
	if (top == NULL) 
    { 
		cout<<"\t\t\t\t\t\t\t\t\t\t\tShopping Club Closed !!"<<endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\nStack Underflow" << endl;
		exit(1); 
	} 
	else 
    {		
		temp = top; 

		cout<<"\t\t\t\t\t\t\t\t\t\t\t Your Trolli No is : "<<top->data<<endl;
    	cout<<" \t\t\t\t\t\t\t\t\t\t\t                 ___"<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t\t\t                /  |"<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t\t\t ______________/   --"<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t\t\t|___/__ /___/_|     "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t\t\t|__/___/___/__|     "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t\t\t|_/___/___/___|     "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t\t\t  _______/         "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t\t\t    O   O           "<<endl;

		top = top->next;  
		temp->next = NULL; 
		
		// release memory of top node 
		free(temp); 		
	}
} 

void bdisplay() 
{ 
	struct bucket* temp; 

	if (top == NULL) 
    { 
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tStack Underflow";
		exit(1); 
	} 
	else 
    { 
		temp = top; 
		while (temp != NULL)
        { 
	        cout << temp->data << " ";  
			temp = temp->next; 
		} 
	} 
} 




