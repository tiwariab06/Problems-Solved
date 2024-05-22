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
 
int height_of_tree(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh=height_of_tree(root->left);
    int rh=height_of_tree(root->right);
    int height= (max(lh,rh))+1;
    return height;
}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    //calculate left diameter
    int ld=diameter(root->left);
    int lh=height_of_tree(root->left);
    //calculate right diameter
    int rd=diameter(root->right);
    int rh=height_of_tree(root->right);
    //calculate the dia that passes through the root 
    int self=lh+rh+1;
    int dia=max(self,max(lh,rh)+1);
    return dia;

}

int32_t main()
{
    fastio;
    binary_tree obj;
    int a[13] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = obj.buildtree(a);
    int ans=diameter(root);
    cout<<ans;

    return 0;
}