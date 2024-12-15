#include <iostream>
#include <queue>
#include <stack>
#include<cmath>
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

// level order traversal in BST :
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

void reverseLevelOrderTraversal(node *root)
{
    stack<node *> s;
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
    s.pop();

    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                continue;
            }
        }
        else
        {
            cout << temp->data << " ";
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // inorder = LNR

    // 1. go to left part
    inorder(root->left);
    // 2.print the node
    cout << root->data << " ";
    // 3. go to right part
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // preorder = NLR

    // 1.print the node
    cout << root->data << " ";
    // 2. go to left part
    preorder(root->left);
    // 3. go to right part
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // postorder = LRN

    // 1. go to left part
    postorder(root->left);
    // 2. go to right part
    postorder(root->right);
    // 3.print the node
    cout << root->data << " ";
}

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

// if target not found then it will return the two numbers from the bst between which the given target will lie
void inorder_succ_nd_pred(node *root, node *&succ, node *&pred, int target)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // if node found
    if (root->data == target)
    {
        // predecessor will be the right most child of leftsubtree or left child itself
        // or predecessor will be a node pointing to the maximum node data in the left subtree
        if (root->left != NULL)
        {
            node *temp = root->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            pred = temp;
        }

        // successor will be the left most child of right subtree or right child itself
        // or it will be a node pointing to the minimum node data in the right subtree
        if (root->right != NULL)
        {
            node *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            succ = temp;
        }

        return;
    }

    // recursive calls :
    if (root->data > target)
    {
        // search in left subtree
        succ = root;
        inorder_succ_nd_pred(root->left, succ, pred, target);
    }
    else
    {
        // search in right subtree
        pred = root;
        inorder_succ_nd_pred(root->right, succ, pred, target);
    }
}
node *minVal(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *maxVal(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
node *delete_From_BST(node *root, int target)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {

            // step 1 : find the minimum node data in the right subtree
            int mini = minVal(root->right)->data;

            // step 2: copy mini into root node
            root->data = mini;

            // step 3: delete the minimum node data
            root->right = delete_From_BST(root->right, mini);
            return root;
        }
    }
    // recursive calls
    if (root->data > target)
    {
        // go to the left subtree
        root->left = delete_From_BST(root->left, target);
        return root;
    }

    // go to the right subtree
    root->right = delete_From_BST(root->right, target);
    return root;
}

int main()
{
    node *root = NULL;
    node *pred = NULL;
    node *succ = NULL;
    cout << "Enter the stream of numbers to be inserted into the BST : " << endl;
    takeinput(root);

    cout << "Printing the level order traversal of the BST : " << endl;
    levelOrderTraversal(root);

    cout << "Printing the reverse level order trversal " << endl;
    reverseLevelOrderTraversal(root);

    cout << endl
         << "Pritning the inorder traversal : ";
    inorder(root);

    cout << endl
         << "Pritning the preorder traversal : ";
    preorder(root);

    cout << endl
         << "Pritning the postorder traversal : ";
    postorder(root);

    inorder_succ_nd_pred(root, succ, pred, 9);
    if (pred != NULL)
        cout << endl
             << "Predecessor is " << pred->data << endl;
    else
        cout << endl
             << "No Predecessor";

    if (succ != NULL)
        cout << endl
             << "Successor is " << succ->data << endl;
    else
        cout << endl
             << "No Successor";

    root = delete_From_BST(root, 30);
    cout << "Printing the level order traversal of the BST : " << endl;
    levelOrderTraversal(root);

    root = delete_From_BST(root, 70);
    cout << "Printing the level order traversal of the BST : " << endl;
    levelOrderTraversal(root);
    
    root = delete_From_BST(root, 50);
    cout << "Printing the level order traversal of the BST : " << endl;
    levelOrderTraversal(root);

    return 0;
}