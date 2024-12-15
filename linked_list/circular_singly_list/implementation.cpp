#include <iostream>
#include <map>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int d)
    {
        this->data = d;
        this->next = 0;
    }

    ~node()
    {
        int value = this->data;
        if(this->next!=NULL){
             delete next;
             next=NULL;
        }
        
        cout << "the value deleted is : " << value << endl;
    }
};

void insertnode(node *&tail, int element, int d)
{
    // assuming that the element is present in the list , and jaise hi element mile uske just aage node insert krdena
    // there will be 3 cases :

    // case 1: empty list
    if (tail == NULL)
    {
        node *newnode = new node(d);
        tail = newnode;
        tail->next = tail;
        // or
        // newnode->next = newnode;
    }
    else
    {
        // non empty list
        node *newnode = new node(d);
        node *temp = tail;
        while (temp->data != element)
        {
            temp = temp->next;
        }

        // element found , temp is pointing that "element" containing node
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// deletion :
void deletenode(node *&tail, int value)
{
    // assuming value is present into the linked list
    // and the node having node data as value is supposed to be deleted

    // case 1: list is empty
    if (tail == NULL)
    {
        cout << "No node to delete , please check again" << endl;
        return;
    }

    node *prev = tail;
    node *current = prev->next;
    // case 2 :  1 node in the list
    if (prev == current)
    {
        prev->next=NULL;
        delete prev;
        tail=NULL;
        return;
    }

    // case 3: in case of >=2 nodes
    while (current->data != value)
    {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;

    if (current == tail)
    {
        tail = current->next;
    }
    
    current->next=NULL;
    delete current;
}

/* one way to print
void print(node *&tail)
{
    node *temp = tail;

    if(tail==0){
        cout<<"List is empty"<<endl;
        return ;
    }
    cout<<temp->data<<" ";
    while(temp->next!=tail){
        temp=temp->next;
         cout<<temp->data<<" ";
    }
    cout<<endl;
}
*/

/*

void print(node *tail)
{

    node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}
*/

void print(node *&tail)
{

    node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);

    cout << endl;
}

bool circular(node *tail)
{
    if (tail == NULL || tail->next == tail)
        return true;
    node *temp = tail->next;
    while (temp != tail && temp != 0)
    {
        temp = temp->next;
    }
    if (temp == tail)
        return true;

    return false;
}

void check(node *head, bool &fl, map<node *, bool> &visited)
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
bool isCircular(node *head)
{
    if (head == NULL)
    {
        return true;
    }
    map<node *, bool> visited;
    bool f = 0;
    check(head, f, visited);
    if (f)
    {
        return true;
    }
    return false;
}

bool floydcyledetect(node *head)
{
    if (head == NULL)
        return true; // if no node is present assume that cycle is present

    if (head->next == NULL) // single node in  singly linked list wont be having a cycle
        return false;

    node *slow = head;
    node *fast = head;

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

node *startingnode(node *head)
{
    if (head == NULL || head->next == head)
        return head; // if no node is present assume that cycle is present

    if (head->next == NULL) // single node in  singly linked list wont be having a cycle
        return NULL;        // since no cycle is present

    node *slow = head;
    node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if (fast == slow) // jaise hi loop chlte vkt fast == slow hogaya usi time return krdo ki yes cycle is present
            break;        // cycle is present
    }

    if(fast==NULL){
        return NULL;  //--> case of singly linked list 
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
                cout << fast->data << " " << slow->data << endl;
                return slow;
            }
        }
    }

    return NULL;
}


int main()
{
    node *tail = 0;
    // if(circular(tail)){
    //     cout<<"List is circular "<<endl;
    // }
    // else{
    //     cout<<"List is not circular "<<endl;
    // }

    // if(isCircular(tail)){
    //      cout<<"List is circular 1 "<<endl;
    // }
    // else{
    //     cout<<"List is not circular 1"<<endl;
    // }

    if (floydcyledetect(tail))
    {
        cout << "List is circular 2 " << endl;
    }
    else
    {
        cout << "List is not circular 2" << endl;
    }

    insertnode(tail, 5, 2); // 2
    print(tail);

    // if only 1 node is there
    if (circular(tail))
    {
        cout << "List is circular " << endl;
    }
    else
    {
        cout << "List is not circular " << endl;
    }

    if (isCircular(tail))
    {
        cout << "List is circular 1 " << endl;
    }
    else
    {
        cout << "List is not circular 1 " << endl;
    }

    if (floydcyledetect(tail))
    {
        cout << "List is circular 2 " << endl;
    }
    else
    {
        cout << "List is not circular 2" << endl;
    }

    insertnode(tail, 2, 5); // 2 5
    print(tail);

    insertnode(tail, 2, 7); // 2 7 5
    print(tail);

    insertnode(tail, 5, 10); // 2 7 5 10
    print(tail);

    insertnode(tail, 2, 12); // 2 12 7 5 10
    print(tail);

    node *loop = startingnode(tail);
    cout << "Beginning cyle node data : " << loop->data << endl;

    if (floydcyledetect(tail))
    {
        cout << "List is circular 2 " << endl;
    }
    else
    {
        cout << "List is not circular 2" << endl;
    }

    deletenode(tail, 2); // 12 7 5 10
    print(tail);

    deletenode(tail, 10); // 12 7 5
    print(tail);

    deletenode(tail, 7); // 12 5
    print(tail);

    return 0;
}