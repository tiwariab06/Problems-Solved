#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    //constructor
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
class binary_tree{
    public:
    int idx=-1;
    Node* buildtree(int a[]){
        idx++;
        Node* NewNode=NULL;
        if(a[idx]==-1){
            return NULL;
        }
        // if(idx>=6){
        //     return NewNode;
        // }
          NewNode= new Node(a[idx]);
        NewNode->left=buildtree(a);
        NewNode->right=buildtree(a);
        return NewNode;
    }
};
bool isidentical(Node *root, Node *subroot)
{
    if (root== NULL && subroot == NULL)
    {
        return true;
    }
    else if (root == NULL || subroot== NULL || root->data != subroot->data)
    {
        return false;
    }
    if (!isidentical(root->left, subroot->left))
    {
        return false;
    }
    if (!isidentical(root->right, subroot->right))
    {
        return false;
    }
    return true;
}

bool issubtree(Node *root, Node *subroot)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == subroot->data)
    {
        if (isidentical(root, subroot))
        {
            return true;
        }
    }
    return issubtree(root->left, subroot) || issubtree(root->right, subroot);
}
int32_t main()
{
    fastio;
    binary_tree obj;
    binary_tree obj1;
    int a[13] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = obj.buildtree(a);
    int b[10]={1, 2, 4, -1, -1, 5, -1, -1, 3, -1};
    Node* subroot=obj1.buildtree(b);
    bool ans=issubtree(root,subroot);
    cout<<ans;
    return 0;
}