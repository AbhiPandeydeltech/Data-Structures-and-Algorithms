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

//insertion 
 void insertathead(Node* & head,int d){
    Node * newnode= new Node(d);
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
 }

 void insertattail(Node*&tail,int d){
     Node * newnode = new Node(d);
     tail->next = newnode;
     newnode->prev = tail;
     tail=newnode;
 }

 void insertatposition(Node*&head, Node*& tail,int d,int position,int length){
     if(position==1){
        insertathead(head,d);
        return ;
     }
     if(position==length+1){
        insertattail(tail,d);
        return ;
     }
    Node* newnode = new Node(d);
    Node* temp = head;
    int cnt=1;
    while(cnt<position-1){
       temp=temp->next;
       cnt++;
    }
    newnode->next=temp->next;
    temp->next->prev = newnode;
    temp->next= newnode;
    newnode->prev= temp;
 }

 //deletion

 void deleteathead(Node*&head){
    Node*temp=head;
    head->next->prev = 0;
    head= head->next;
    temp->next=NULL;
    delete temp;
 }

 void deleteattail(Node*&tail){
    Node*temp=tail;
    tail->prev->next=0;
    tail=tail->prev;
    temp->prev=NULL;
    delete temp;
 }

 void deleteatposition(Node*&head,Node*&tail,int position){
    if(position==1){
        deleteathead(head);
        return ;
    }
    Node* currentnode = head;
    Node * prevnode = NULL ;
    int cnt=1;
    while(cnt<position){
        prevnode=currentnode;
        currentnode=currentnode->next;
        cnt++;
    }
    if(currentnode==tail){
        deleteattail(tail);
        return ;
    }
    prevnode->next=currentnode->next;
    currentnode->next->prev=prevnode;
    currentnode->next=NULL;
    currentnode->prev=NULL;
    delete currentnode;
 }

void print(Node* &head){
    Node* temp=head;
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getlength(Node*&head){
  Node * temp =head;
  int count=0;
  while(temp!=0){
    temp=temp->next;
    count++;
  }
  return count;
}

int main(){
    
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail= node1;
    
    print(head); //10
    cout<<"Length is : "<<getlength(head)<<endl;

    insertathead(head,20);
    print(head); //20 10
    cout<<"Length is : "<<getlength(head)<<endl;

    insertattail(tail,30);
    print(head); // 20 10 30
    cout<<"Length is : "<<getlength(head)<<endl;

    insertatposition(head,tail,40,1,getlength(head)); //40 20 10 30
    print(head);
    cout<<"Length is : "<<getlength(head)<<endl;

    insertatposition(head,tail,50,getlength(head)+1,getlength(head)); // 40 20 10 30 50
    print(head);
    cout<<"Length is : "<<getlength(head)<<endl;

    insertatposition(head,tail,60,3,getlength(head)); //40 20 60 10 30 50 
    print(head);
    cout<<"Length is : "<<getlength(head)<<endl;

    deleteathead(head); //20 60 10 30 50
    print(head);
    cout<<"Length is : "<<getlength(head)<<endl;

    deleteattail(tail); //20 60 10 30
    print(head);
    cout<<"Length is : "<<getlength(head)<<endl;

    deleteatposition(head,tail,1); //60 10 30
    print(head);
    cout<<"Length is : "<<getlength(head)<<endl;

    deleteatposition(head,tail,3); //60 10
    print(head);
    cout<<"Length is : "<<getlength(head)<<endl;

    insertattail(tail,100); //60 10 100
    print(head);
    cout<<"Length is : "<<getlength(head)<<endl;

    deleteatposition(head,tail,2); //60 100 
    print(head);
    cout<<"Length is : "<<getlength(head)<<endl;

    

    return 0;
}