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
        Node *NewNode = NULL;
        if (a[idx] == -1)
        {
            return NULL;
        }
        // if(idx>=6){
        //     return NewNode;
        // }
        NewNode = new Node(a[idx]);
        NewNode->left = buildtree(a);
        NewNode->right = buildtree(a);
        return NewNode;
    }
};
Node* lca(Node *root, int n1, int n2)
{
    if (root == NULL || root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *ls = lca(root->left, n1, n2);
    Node *rs = lca(root->right, n1, n2);
    if(rs==NULL){
        return ls;
    }
    if(ls==NULL){
        return rs;
    }
    if(ls!=NULL&&rs!=NULL){
        return root;
    }
    return root;
}
// kth level nodes printing
//  void kth_level(Node*root,int clvl,int k){
//      if(root==NULL){
//          return;
//      }
//      if(clvl==k){
//          cout<<root->data<<" ";
//      }
//      kth_level(root->left,clvl+1,k);
//      kth_level(root->right,clvl+1,k);
//  }
int32_t main()
{
    fastio;
    binary_tree obj;
    int a[13] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = obj.buildtree(a);
    // cout<<root->data;
    Node* ans=lca(root, 4, 6);
    cout<<ans->data;
    return 0;
}