#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor :
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // this class has its own inbuilt destructor but am making one :
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            next=NULL;
            delete next;
        }

/*      ---> The above thing as destructor is absolutely same as below
    ~Node(){
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        }
*/
        cout << "memory is free for value : " << value << endl;
    }
};

// passing head and tail and reference because i dont want to create any copy and make a mess

// insertion
void insertathead(Node *&head, int d)
{
    // new node which is supposed to be inserted at beginning or insert at head
    Node *newnode = new Node(d);
    newnode->next = head;
    head = newnode;
}

void insertattail(Node *&tail, int d)
{
    Node *newnode = new Node(d);
    tail->next = newnode;
    tail = newnode;
}

void insertatposition(Node *&head, Node *&tail, int d, int position)
{
    if (position == 1)
    {
        insertathead(head, d);
        return;
    }
    
    Node *temp = head;
    int cnt = 1;
    while(cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        //    temp->next=newnode;
        //    tail=newnode;
        // or
        insertattail(tail, d);
        return;
    }
    Node *newnode = new Node(d);
    newnode->next = temp->next;
    temp->next = newnode;
}

// deletion :
void deleteathead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp; // ye call hote hi destructor call hua hoga aur temp->next me NULL and temp jis node ko point krrha hai usko delete
}

void deleteattail(Node *&tail, Node *&head)
{
    Node *temp = head;
    Node *temp2 = tail; // it will be used for deleting the node at the end
    if(temp->next==NULL){
        deleteathead(head);
        return ;
    }

    /*
        while(temp->next!=tail){
            temp=temp->next;
        }
    */
    while (temp->next->next != 0)
    {
        temp = temp->next;
    }
    // after the above while loop terminates temp will point the node just before the node pointed by tail
    temp->next = NULL;
    tail = temp;
    delete temp2;
}
void deleteatposition(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        deleteathead(head);
        return;
    }
    int cnt = 1;
    Node *temp = head;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // if temp is pointing a node just before the node pointed by tail
    if (temp->next->next == 0)
    {
        deleteattail(tail, head);
        return;
    }

    Node *temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = NULL;

    delete temp2;
}

void print(Node *&head)
{
    if(head==NULL){
        cout<<"List is Empty"<<endl;
        return ;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool circular(Node *tail)
{
    if (tail == NULL || tail->next == tail)
        return true;
    Node *temp = tail->next;
    while (temp != tail && temp != 0)
    {
        temp = temp->next;
    }
    if (temp == tail)
        return true;

    return false;
}

void check(Node *head, bool &fl, map<Node *, bool> &visited)
{

    if (head == NULL)
    {
        return;
    }

    if (!visited[head])
    {
        visited[head] = true;
        check(head->next, fl, visited);
    }
    else
    {
        fl = 1;
        return;
    }
}
bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    map<Node *, bool> visited;
    bool f = 0;
    check(head, f, visited);
    if (f)
    {
        return true;
    }
    return false;
}

bool floydcyledetect(Node *head)
{
    if (head == NULL)
        return true; // if no node is present assume that cycle is present

    if (head->next == NULL) // single node in  singly linked list wont be having a cycle
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if (fast == slow) // jaise hi loop chlte vkt fast == slow hogaya usi time return krdo ki yes cycle is present
            return true;  // cycle is present
    }

    return false;
}

Node *startingnode(Node *head)
{
    if (head == NULL || head->next == head)
        return head; // if no node is present assume that cycle is present

    if (head->next == NULL) // single node in  singly linked list wont be having a cycle
        return NULL;        // since no cycle is present

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if (fast == slow) // jaise hi loop chlte vkt fast == slow hogaya usi time return krdo ki yes cycle is present
            break;        // cycle is present
    }

    if (fast == NULL)
    {
        return NULL; //--> case of singly linked list
    }

    if (slow == head && fast == head)
        return head;

    else
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;

            if (slow == fast)
            {
                return slow;
            }
        }
    }

    return NULL;
}

void remove_loop(Node *tail)
{
    Node *start = startingnode(tail);
    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
int main()
{
    // created a new node dynamically
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    // Node * head=node1;
    Node *head = node1;
    Node *tail = node1;

    // if (circular(head))
    // {
    //     cout << "List is circular " << endl;
    // }
    // else
    // {
    //     cout << "List is not circular " << endl;
    // }

    // if (isCircular(head))
    // {
    //     cout << "List is circular 1 " << endl;
    // }
    // else
    // {
    //     cout << "List is not circular 1" << endl;
    // }
    if (floydcyledetect(head))
    {
        cout << "List is circular 2 " << endl;
    }
    else
    {
        cout << "List is not circular 2" << endl;
    }

    cout << "Linked list before insertion at head : " << endl; // 10
    print(head);

    insertathead(head, 20);
    cout << "linked list after insertion at head : " << endl; // 20 10
    print(head);

    insertattail(tail, 30);
    print(head); // 20 10 30

    /*
        tail->next=head->next;
        floyd detectio algorithm working fine here
        if(floydcyledetect(head)){
            cout << "List is circular 2 " << endl;
        }
        else
        {
            cout << "List is not circular 2" << endl;
        }

        Node*loop=startingnode(head);
        cout<<"Beginning cycle node data : "<<loop->data<<endl;  //--> working fine

        remove_loop(head);
        print(head);
    */
    insertatposition(head, tail, 15, 3); // 20 10 15 30
    print(head);

    insertatposition(head, tail, 5, 1); // 5,20 10 15 30
    print(head);

    insertatposition(head, tail, 50, 6); // 5,20 10 15 30 50
    print(head);

    // if (isCircular(head))
    // {
    //     cout << "List is circular 1 " << endl;
    // }
    // else
    // {
    //     cout << "List is not circular 1" << endl;
    // }

    // cout << "head->data : " << head->data << endl;
    // cout << "tail->data : " << tail->data << endl;

    deleteathead(head);
    print(head); // 20 10 15 30 50

    // cout << "head->data : " << head->data << endl;
    // cout << "tail->data : " << tail->data << endl;

    deleteattail(tail, head);
    print(head); // 20 10 15 30

    // cout << "head->data : " << head->data << endl;
    // cout << "tail->data : " << tail->data << endl;

    deleteatposition(1, head, tail);
    print(head); // 10 15 30

    // deleteatposition(3, head, tail);
    // print(head); // 10 15

    // insertathead(head, 100);
    // print(head); // 100 10 15

    deleteatposition(2, head, tail);
    print(head); 

    return 0;
}