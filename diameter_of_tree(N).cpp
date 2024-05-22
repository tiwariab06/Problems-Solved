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
class info
{
public:
    int dia;
    int ht;
    // constructor
    // default constructor is invoked automatically when we create an object but if we have created a parameterized constructor then we have to invoke it manualy
    info(int d, int h)
    {
        this->dia = d;
        this->ht = h;
    }
};
info diameter(Node *root)
{
    if (root == NULL)
    {   // if we are creating an object and intialising its values using the new keyword like-
        //  new info(xyz,xyz) then we have to create the object with pointer reference like--
        // info* obj=new info(0,0);

        info obj = info(0,0);
        obj.dia = 0;
        obj.ht = 0;
        return obj;
    }
    info linfo = diameter(root->left);
    info rinfo = diameter(root->right);
    int temp = max(linfo.dia, rinfo.dia);
    int diam = max(temp, (linfo.ht + rinfo.ht + 1));
    int h = max(linfo.ht, rinfo.ht) + 1;
    info d_mtr=info(0,0);
    d_mtr.dia = diam;
    d_mtr.ht = h;
    return d_mtr;
}
int32_t main()
{
    fastio;
    binary_tree obj;
    int a[13] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = obj.buildtree(a);

    info ans = diameter(root);
    cout << ans.dia;

    return 0;
}