#include <iostream>
#include <queue>
#include<stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data : ";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    cout << "Enter the data for inserting in the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

/* op of this is in single line but i want them in  the form of a tree
void levelOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }

}
*/

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // ek level complete ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // still have child node
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraversal(node*root){
    stack<node*>s;
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp == NULL)
        {
            if (!q.empty())
            {
                // still have child node
                q.push(NULL);
            }
        }
        else
        {
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }
    s.pop(); //last level ke baad jo null store hoga queue me usko htane ke liye 

    while(!s.empty()){
        node *temp = s.top();
        s.pop();

        if(temp==NULL){
            cout<<endl;
        }
        else{
            cout << temp->data << " ";
        }
    } 
    
}

void inorder(node*root){
   if(root==NULL){
    return ; 
   }

   //inorder = LNR 
   
   //1. go to left part 
   inorder(root->left);
   //2.print the node 
   cout<<root->data<<" ";
   //3. go to right part 
   inorder(root->right);
}

void preorder(node*root){
   if(root==NULL){
    return ; 
   }

   //preorder = NLR 
   
   //1.print the node 
   cout<<root->data<<" ";
   //2. go to left part 
   preorder(root->left);
   //3. go to right part 
   preorder(root->right);
}

void postorder(node*root){
    if(root==NULL){
    return ; 
   }

   //postorder = LRN 
   
   //1. go to left part 
   postorder(root->left);
   //2. go to right part 
   postorder(root->right);
   //3.print the node 
   cout<<root->data<<" ";
   
}

void inorder2(node*root){
    stack<node*>s;
    node*temp = root;

    while(temp!=NULL || !s.empty()){
        //left portion 
        while(temp!=NULL){
            s.push(temp);
            temp = temp->left;
        }

        //here temp must have reached left null 
        temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        
         // we have visited the node and its
        // left subtree.  Now, it's right
        // subtree's turn

        temp = temp->right;
    } 
}

void preorder2(node*root){
    stack<node*>s;
    s.push(root);
   while (!s.empty()) {
        // Pop the top item from stack and print it
        node*temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        // Push right and left children of the popped node to stack
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

void postorder2(node*root){
    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);

    while(!s1.empty()){
        node*temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left){
          s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        } 
    }

    //print all elements of the second stack 
    while(!s2.empty()){
        node*temp = s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
}

//creation of tree using levelordertraversal

void buildFromLevelOrderTraversal(node*&root){
    queue<node*>q;
    cout<<"Enter the data : ";
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();
        
        cout<<"Enter the left node of "<<temp->data<<" : ";
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        
        cout<<"Enter the right node of "<<temp->data<<" : ";
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{

    node *root = NULL;
    node *root1=NULL;
    //building tree using recursion
    root = buildTree(root);

    // //building tree from level order 
    // buildFromLevelOrderTraversal(root1);
    
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Printing the level order traversal  " << endl;
    levelOrderTraversal(root);

    // //1 2 3 4 5  6 7 -1 -1 -1 -1 -1 -1 -1 -1
    // cout << "Printing the level order traversal  " << endl;
    // levelOrderTraversal(root1);

    

    cout<<"Printing the reverse level order trversal "<<endl;
    reverseLevelOrderTraversal(root);

    // cout<<endl<<"Pritning the inorder traversal : ";
    // inorder(root);

    // cout<<endl<<"Pritning the preorder traversal : ";
    // preorder(root);

    // cout<<endl<<"Pritning the postorder traversal : ";
    // postorder(root);

    // cout<<endl<<"Pritning the inorder traversal : ";
    // inorder2(root);

    // cout<<endl<<"Pritning the preorder traversal : ";
    // preorder2(root);

    // cout<<endl<<"Pritning the postorder traversal : ";
    // postorder2(root);

    return 0;
}