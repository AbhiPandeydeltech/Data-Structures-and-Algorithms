#include <iostream>
#include <queue>
#include <stack>
#include<cmath>
#include<vector>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    // making a constructor :
    node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

node *insert_into_BST(node *root, int d)
{
    // base case :
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insert_into_BST(root->right, d);
    }
    else
    {
        root->left = insert_into_BST(root->left, d);
    }
    return root;
}
void takeinput(node *&root)
{
    int data;
    cin >> data;

    // jbtk data = -1 na ho jae tbtk input lo
    while (data != -1)
    {
        root = insert_into_BST(root, data);
        cin >> data;
    }
}

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

void inorderArray(node* root,vector<int>&inorder){
    if(root==NULL){
      return ;  
    }

    //inorder : LNR

    //step 1 : L
    inorderArray(root->left,inorder);
    //step 2 : N
    inorder.push_back(root->data);
    //step 3 : R
    inorderArray(root->right,inorder);
}

void printInorder(vector<int>inorder){
    for(int i:inorder){
        cout<<i<<" ";
    }
    cout<<endl;
}
void convert(node* root,vector<int>&inorder,int &index,int n){
    //traverse like preorder and put inorder values accordingly
    if(root==NULL){
        return ;
    }
    
    if(index>=n){
        return ;
    }
    //preorder : NLR 
    //step 1 : N
    root->data = inorder[index++];
    
    //step 2 : L
    convert(root->left,inorder,index,n);
    //step 3 : R
    convert(root->right,inorder,index,n);
}
int main(){
    
    //question : convert BST into min heap , with 1)the final tree will follow min heap property 
    //2) all the values in the left subtree should be smaller than all the values in the right subtree 
    node *root = NULL;
    cout << "Enter the stream of numbers to be inserted into the BST : " << endl;
    takeinput(root);

    cout<<"BST before converting it into min heap : "<<endl;
    levelOrderTraversal(root);
    vector<int>inorder;
    inorderArray(root,inorder);
    cout<<"Printing the inorder : "<<endl;
    printInorder(inorder);
    
    int n = inorder.size();
    cout<<"BST in converted to min heap with 2 condtions stated above accordinlgy "<<endl;
    int index = 0 ;
    convert(root,inorder,index,n);
    cout<<"tree after converting it into min heap : "<<endl;
    levelOrderTraversal(root);
    return 0;
}