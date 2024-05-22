#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl cout << endl;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// Make a node class
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // constructor
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class binary_tree
{
public:
    int idx = -1;
    Node *buildtree(int a[])
    {
        idx++;
        if (a[idx] == -1)
        {
            return NULL;
        }
        Node *NewNode = new Node(a[idx]);
        NewNode->left = buildtree(a);
        NewNode->right = buildtree(a);
        return NewNode;
    }
};
// preorder traversal
//  rules of preorder root->left->right
void preorder(Node *root)
{
    if (root == NULL || root->data == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// inorder traversal
// rules left->root->right
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// postorder traversal
// rules left->right->root
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// level order traversal BFS
//  traverse along the breadth first it uses a queue to do so
void levelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!(q.empty()))
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            nl;
            if (q.empty())
            {
                break;
            }
            else
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}
void levelorder_withoutnextline(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!(q.empty()))
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

int32_t main()
{
    fastio;
    binary_tree obj;
    int a[13] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = obj.buildtree(a);
    preorder(root);
    nl
        inorder(root);
    nl
        postorder(root);
    nl
        levelorder_withoutnextline(root);
    nl
        levelorder(root);
    return 0;
}