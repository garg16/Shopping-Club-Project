
#include<bits/stdc++.h>
using namespace std; 

// Implemented with the help of Queue using Linked List with Nodes.
// Each Node will contain customer's name and next Node's address.

struct Node
{
    string cname;
    Node *next;
};

Node *front = NULL;                 // Head of the Linked List    
Node *rear = NULL;                  // Tail of the Linked List

//Function to check if queue is empty or not
bool isempty()
{
    if(front == NULL && rear == NULL)  return true;
    else   return false;
}

//Function to enter elements(Customer's name) in queue
void enqueue ( string name )
{
    Node *Cust = new Node();
    Cust->cname= name;
    Cust->next = NULL;
    
    if( front == NULL )            // If inserting the first element/node
    {
       front = Cust;
       rear = Cust;
    }
    
    else                           
    {
       rear ->next = Cust;         // Otherwise, inserting the Cust Node next to the tail(rear)
       rear = Cust;                // And then making the Cust Node as the new tail(rear)
    }

}

//Function to delete/remove element from queue
void dequeue ()
{
    if(isempty())
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\tQueue is empty\n";
    }
    else                            
    {
        if( front == rear)              // Only one element/node in the queue
        {
            free(front);
            front = rear = NULL;
        }
        else                           // Otherwise, remove the head(front)
        {
            Node *temp = front;
            front = front->next;       // And make the one next to head(front) as head(front)
            free(temp);
        }
    }
}

//Function to show the element at front
void showfront( )
{
    if( isempty())
    cout<<"\t\t\t\t\t\t\t\t\t\t\tQueue is empty\n";
    else
    cout<<"\t\t\t\t\t\t\t\t\t\t\telement at front is:"<<front->cname<<"\n";
}

//Function to display queue
void displayQueue()
{  
    if (isempty())
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\tQueue is empty\n";
    }
    else
    {
        Node *Cust = front;
        while( Cust !=NULL)
        {
            cout<<"\t\t\t\t\t\t\t\t\t\t\t"<<Cust->cname<<"\t\t\t\t\t\t\t\t\t\t\t "<<endl;
            Cust= Cust->next;

        }
    }
}
