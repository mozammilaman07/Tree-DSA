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

int main()
{
    Node *root = createTree();

    return 0;
}