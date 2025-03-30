#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    cout << "enter the value for node: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    root->left = createTree();

    root->right = createTree();
    return root;
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // NLR
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
};

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // LNR
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // LRN
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = createTree();

    cout << "Printing preOder: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Printing inorder: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Printing postOrder: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}