#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root) // Inorder Traversal (Left → Root → Right)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root) // Preorder Traversal (Root → Left → Right)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) // Postorder Traversal (Left → Right → Root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "in-order: ";
    inorder(root);
    cout << endl;

    cout << "pre-order: ";
    preorder(root);
    cout << endl;

    cout << "post-order: ";
    postorder(root);
    cout << endl;

    return 0;
}

/*
This will not traverse. It will only print last element. Recursion winds up but it did not unwind it. It is a just introductory lecture.
*/

// For step by step guide follow this link:
// https://www.kimi.com/share/19e8760a-7ff2-8687-8000-000043382560
