#include <bits/stdc++.h>
#include"Customer.h"
#include"Cart.h"
using namespace std;

class node
{
    int ID;
    string proName;
    double proPrice;
    int quantity;
     
     
    public:
         node* next;
         int search(int);
         void addPro();
         void delPro();
         void modify();
         int display();
        void buy();
};

node *head=NULL;

void node::addPro()

{
    int id,quant;
    string name;
    double price;
    node *NewProd=new node;
    node *temp=head;

    cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter product ID:- ";
    cin>>id;
    int a = search(id);
    if(a==-1)
    NewProd->ID=id;
    else
   { cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tThis Id is already Present, Please enter a unique id."<<endl;
    return;}
    cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter product Name:- ";
    cin>>name;
    NewProd->proName=name;
    cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter product price:- ";
    cin>>price;
    NewProd->proPrice=price;
    cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter product quantity:- ";
    cin>>quant;
    NewProd->quantity=quant;

    if(head==NULL)
    {
    NewProd->next=NULL;
    head=NewProd;
    }

    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NewProd;
        NewProd->next=NULL;
    }

    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tThis product is Inserted!\n\n\n";

}


int node::search(int id)
{
     int pos = 1;                        // pos is for the position of the searched product
    node *temp = head;
     while(temp!=NULL)
     {
         if(temp->ID == id)                // When we've found out the required product, return that position no.
             return pos;
         else
             pos++ ;
             temp=temp->next;
    }
     return -1;
 }

void node::delPro()
{
    
    display();
    int id;
    node *curr=head;
    node *prev=NULL;

    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tEnter ID to delete that product: ";
    cin>>id;

    if (head == NULL)
    {
       
        cout<<"\t\t\t\t\t\t\t\t\t\t\t List is empty"<<endl;
    }

    int totProd = display();                        // Gives the total no of nodes i.e., total no. of products
    int pos=search(id);                             // Gives the position of the product which we want to delete
    
    if(pos <= totProd && pos!=-1)                   // Product exists if pos<=totProd and if pos!=-1
    {                                               // and so we'll move forward in if statement
        while(curr->ID!=id)
        {
            prev=curr;
            curr=curr->next;
        }                                           // The node which is to be deleted is curr cz curr->ID == id
                                                  
        if(prev!=NULL)
            prev->next=curr->next;                  // We'll skip curr and directly connect prev to the node next to curr
        else
            head = head->next;                      // If prev==NULL, then that means the node which we want to delete is head itself.
                                                    // So, we'll just make head->next as head
       
    }

    else
    {
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t<<<Not found>>\n\n";
    }
}


int node::display()
{
   
    int totProd=0;                             // Gives the total no of nodes i.e., total no. of products
    node *temp=head;
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\tExisting products are:\n\n\n1";
    cout<<"\t\t\t\t\t\t\t\t\t\t\tID\t\tProduct Name\t\t Price\t\tQuantity\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t|=================================================================|\n";
    while(temp!=NULL)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t"<<temp->ID<<"\t\t"<<temp->proName<<"\t\t\t\t\t"<<temp->proPrice<<"\t\t\t"<<temp->quantity<<"\n";
        temp=temp->next;
        totProd++;
    }
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTotal products in our store is : "<<totProd<<"\n\n\n";
    return totProd;
}




void node::modify()
{
    int id;                                    // Current id
    int nid; int nquant;                       // nid for new id , nquant for new quantity for that product
    double nprice;                          // nprice for new price
    string nName;                            // nName for new product name

    if (head == NULL)
    {
      
        cout<<"\t\t\t\t\t\t\t\t\t\t\t List is empty"<<endl;
    }

    else
    {
        display();
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tEnter ID to modify product Name and its price: ";
        cin>>id;
        struct node *temp=head;
        int totProd = display();                // Gives the total no of nodes i.e., total no. of products
        int pos = search(id);                    // Gives the position of the product which we want to modify
                                            
        if(pos<=totProd)                        // To check weather the desired product exists or not
        {                                         // If exists then enter into the if condn and modify the product with new id, new name, new quant
            while(temp->ID!=id)
            {
                temp=temp->next;
            }
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\tOld ID : "<<temp->ID<<endl;
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\tOld Name : "<<temp->proName<<endl;
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\tOld Price : "<<temp->proPrice<<endl;
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\tOld Quantity : "<<temp->quantity<<endl;

            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter new ID: ";
            cin>>nid;
            temp->ID=nid;
            cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter new Name: ";
            cin>>nName;
            temp->proName=nName;
            cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter new Price: ";
            cin>>nprice;
            temp->proPrice=nprice;
            cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter new Quantity: ";
            cin>>nquant;
            temp->quantity=nquant;
        }

        else
        {
            cout<<id<<" \t\t\t\t\t\t\t\t\t\t\tis <<<Not found>>\n\n";
        }
    }
}


void node::buy()
{

    display();
    string products[20];                // String array to display sold items
    
    int Totprice =0 , FinalBill = 0;    // Totprice is price before discount and FinalBill is price after discount
    int c=0 ;                            // c maintains the index of products[] array

    if(head==NULL)
    {
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t<<<<There are no items to buy>>>>\n\n";
    }

    else
    {
        int no;                                                    // no is for the total products customer wants to buy
        cout<<"\t\t\t\t\t\t\t\t\t\t\tHow many Products you want to buy -->> ";
        cin>>no;
        int totProd = display();                                   // Gives the total no of nodes i.e., total no. of products

        int i =1;
        while (i<=no)
        {
            node *temp = head;
            int quant ;

            a:
            cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter id of the product that you want to buy: ";
            int id ;
            cin>>id;
            if(id==-1)
            {
              
                return;
            }
            
            int pos = search(id);                              // Gives the position of the product which we want to buy
            if(pos<=totProd)                                    // If the item is available, then go into the if condn
            {
                while(temp->ID!=id)
                {
                    temp=temp->next;
                }

                cout<<"\t\t\t\t\t\t\t\t\t\t\tHow many quantities you want: ";
                cin>>quant;

                if(temp->quantity<quant)
                {
                   cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t----The Quantity You Entered is not available---"<<endl;
                   cout<<"\n\t\t\t\t\t\t\t\t\t\t\t-----(press -1 to go Back to Main Menu)------"<<endl;
                   goto a;
                }

                products[c]=temp->proName;               // this will conatin the items buy names in array
                c++;

                Totprice = Totprice + (temp->proPrice*quant);        // Calculate the Final Bill
                temp->quantity = temp->quantity - quant;              // Change quantity

                i++;
            }

            else
            {
                cout<<"\n\t\t\t\t\t\t\t\t\t\t\t<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
            }

        }

        string customer;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t Enter Your Name : ";
        cin>>customer;
        enqueue(customer);

        
        cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYou have bought : ";
        for(int i=0;i<no;i++)                           // Shows the items you have bought
        {
            cout<<products[i]<<",";
        }

        FinalBill = Totprice*(0.90);                       // Final Bill with 10% discount
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tOriginal price : " << Totprice;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\twith 10% discount: " <<FinalBill<< "\n\n\n\t\t\t\t\t\t\t\t\t\t\tThank you "<< customer << " for the shopping\n\n";

    }
}



void Admin()
{ int ch;
    node prod;
       
    
        cout<<"\t\t\t\t\t\t\t\t\t\t\t ============================================"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t|          Administrator Portal              |"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t ============================================"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t     Enter 1 to Add a new product    "<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t     Enter 2 to Display all the products   "<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t     Enter 3 to Modify existing products "<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t     Enter 4 to Delete a particular product item"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t     Enter 5 for Customers List "<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t     Enter 6 to Dequeue customer"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t     Enter 0 for Main Menu"<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter your choice >>> ";
        cin>>ch;
      switch(ch)
    {
        case 1:                                            // To add new products
          prod.addPro();
            break;
        case 2:                                            // To display all products
            prod.display();
            break;
        case 3:                                            // To modify any product
            prod.modify();
            
            break;
        case 4:                                            // To delete any product
            prod.delPro();
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t-------Product is Deleted-------\n";
            break;
        case 5:                                            // To display the queue of customers (Customer.h)
            
              cout<<"\t\t\t\t\t\t\t\t\t\t\t|============CUSTOMERS NAMES LIST==============|"<<endl;
              displayQueue();
           break;
        case 6:                                   // To dequeue the customer. Dequeing will start from the 1st customer who came for shopping as it happens in real life also.
          cout<<"\t\t\t\t\t\t\t\t\t\t\t|============CUSTOMERS NAMES LIST==============|"<<endl;
              dequeue();
              displayQueue();                             // The new queue of the customers will be displayed
            break;
        default:                                        // If we type any number other than 1,2,3,4,5,6 then
            break;                         // it'll clear the sreen and again brings the customer to the main menu
    }
        
    
}

                          
int main()
{
    int i=50;
       while(i>=1)
    {
        push(i--);   // Pushing into stack. These are our bucket numbers (topmost bucket labelled as 50 and the last will be 1)
    }

    node prodBuy;
    
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------\n\n"<<endl;
    
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t||             Shopping Club System                ||\n\n"<<endl;
    
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------\n\n"<<endl;
       
       
       cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t>>>-----------  Project Implemented By  ------------<<<\n\n"<<endl;
       cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t>>>------------    Vaibhav Garg   -----------<<<"<<endl;
            
   
    
    int ch=0;
    while(ch!=3)
    {
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t |---------- <Main Menu>  -----------|";
        cout<<"\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t 1)Administator of Market\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t 2)Customer               \n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t 3)Exit                    \n";

        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t Enter Your choice >>> ";
        cin>>ch;
        // Baesd on our choice, that particular case will be selected
    
        switch(ch)
        {
            case 1:
                Admin();
                break;

            case 2:
              
                cout<<endl<<endl;
                bpop();
                // The cart which is provided to the customer gets popped out from the stack.
               
                prodBuy.buy();
                break;

            case 3:
                 cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t >>>-------- Thank You --------<<< \t\t\t\t\n\n\n\n";
                break;
        }
    }

    return 0;
}



