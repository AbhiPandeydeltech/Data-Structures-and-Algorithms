#include <iostream>
using namespace std;

class Node{
   public:
   int data;
   Node *next;
   Node* prev;

   //constructor
   Node(int data){
     this->data=data;
     this->next=0;
     this->prev=0;
   }

   //destructor
   ~Node(){
    int value = this->data;
    if(this->next!=NULL){
      delete next;
      next=NULL;
    }
    if(this->prev!=NULL){
      delete prev;
      prev=NULL;
    }
    
    cout<<"memory is free for value : "<<value<<endl;
   }
};

void insertnode(Node *&tail, int element, int d)
{
    // assuming that the element is present in the list , and jaise hi element mile uske just aage node insert krdena
    // there will be 3 cases :

    // case 1: empty list
    if (tail == NULL)
    {
        Node *newnode = new Node(d);
        tail = newnode;
        tail->next = tail;
        tail->prev=tail;
        // or
        // newnode->next = newnode;
    }
    else
    {
        // non empty list
        Node *newnode = new Node(d);
        Node *temp = tail;
        while (temp->data != element)
        {
            temp = temp->next;
        }

        // element found , temp is pointing that "element" containing node
        temp->next->prev=newnode;
        newnode->next = temp->next;
        temp->next = newnode;
        // temp->prev=newnode;
        newnode->prev=temp;
    }
}

void print(Node*& tail){
    Node* temp = tail;
    if(temp==NULL){
        cout<<"List is Empty"<<endl;
        return ;
    }

    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail);

    cout<<endl;
}

// deletion :
void deletenode(Node *&tail, int value)
{
    // assuming value is present into the linked list
    // and the node having node data as value is supposed to be deleted

    // case 1: list is empty
    if (tail == NULL)
    {
        cout << "No node to delete , please check again" << endl;
        return;
    }

    Node* previous = tail;
    Node* current = previous->next;
    // case 2 :  1 node in the list
    if (previous == current)
    {
        current->next=NULL;
        current->prev=NULL;
        delete current;
        tail=NULL;
        return ;
    }

    // case 3: in case of >=2 nodes
    while (current->data != value)
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    current->next->prev = previous;

    if (current == tail)
    {
        tail = current->next;
    }
    
    current->next=NULL;
    current->prev=NULL;
    delete current;
}

int main(){
    
    Node* tail=NULL;
    deletenode(tail,2);
    insertnode(tail,5,2); //2
    print(tail);

    deletenode(tail,2);
    print(tail);

    insertnode(tail,2,5); //5
    print(tail);
  
    insertnode(tail,5,7);
    print(tail);
    
    insertnode(tail,7,3);
    print(tail);

    insertnode(tail,3,8);
    print(tail);

    // deletenode(tail,5);
    // print(tail);

    deletenode(tail,3);
    print(tail);

    deletenode(tail,8);
    print(tail);

    return 0;
}