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
// create a class which will store the horizontal distance and node
class info
{
public:
    Node *root;
    int hd;
    // constructor
    info(Node *root, int hd)
    {
      this->root=root;
      this->hd=hd;
    }
};
// perform level order traversal and use map to store hd node pairs
void top_views(Node *root)
{      
    // create to queue to do level order travesal
    queue<info *> q;
    q.push(new info(root, 0));
    // q.push(obj);
    q.push(NULL);
    map<int, Node *> mp;
    int mini = 0;
    int maxi = 0;
    while (!(q.empty()))
    {
        info *curr = q.front();
         q.pop();
        if (curr->root == NULL)
        {
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

            if (mp.find(curr->hd) == mp.end())
            {
                mp.emplace(curr->hd, curr->root);
            }
            if ((curr->root->left) != NULL)
            {
                q.push(new info(curr->root->left, curr->hd - 1));

                mini = min(mini, curr->hd - 1);
            }
            if ((curr->root->right) != NULL)
            {
                q.push(new info(curr->root->right, curr->hd + 1));
                maxi = max(maxi, curr->hd + 1);
            }
        }
    }
    // for (int i = mini; i <= maxi; i++)
    // {
    //     cout << i;
    // }
  return;
}

int32_t main()
{
    fastio;
    binary_tree obj;
    int a[13] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = obj.buildtree(a);
    top_views(root);
    cout<<root->data;
    return 0;
}