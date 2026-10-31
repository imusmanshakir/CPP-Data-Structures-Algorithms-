#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
static int idx = -1;
Node *buildTree(vector<int> &preorder)
{
    idx++;
    if (preorder[idx] == -1)
        return nullptr;

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
};

int height(Node *root)
{
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int diameter(Node *root)
{
    if (root == nullptr)
        return 0;
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    int rootDiameter = height(root->left) + height(root->right);
    return max(leftDiameter, max(rightDiameter, rootDiameter));
}

void deleteTree(Node *root)
{
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    cout << "Height: " << height(root) << endl;
    cout << "Diameter: " << diameter(root) << endl;

    deleteTree(root);

    return 0;
}