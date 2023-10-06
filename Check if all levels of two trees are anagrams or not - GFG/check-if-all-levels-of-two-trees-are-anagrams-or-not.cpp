//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
bool solve(vector<int>&a,vector<int>&b)
{
    if(a.size()!=b.size())
    {
        return 0;
    }
    unordered_map<int,int>mp;
    for(int i=0;i<a.size();i++)
    {
        // cout<<a[i]<<" ";
        mp[a[i]]++;
    }
    for(int i=0;i<b.size();i++)
    {
        if(!mp.count(b[i]))
        {
            return 0;
        }
        mp[b[i]]--;
    }
    return 1;
}
    bool areAnagrams(Node *root1, Node *root2)
    {
        queue<Node*>q1;
        queue<Node*>q2;
        q1.push(root1);
        q1.push(NULL);
        q2.push(root2);
        q2.push(NULL);
        if (root1->data!=root2->data)
        return 0;
        vector<int>x;
        vector<int>y;
        while (!q1.empty())
        {
            Node*a=q1.front();
            q1.pop();
            Node*b=q2.front();
            q2.pop();
            if (a)
            {
                x.push_back(a->data);
                if (a->left)
                {
                    q1.push(a->left);
                }
                if (a->right)
                {
                    q1.push(a->right);
                }
            }
            if (b)
            {
                y.push_back(b->data);
                if (b->left)
                {
                    q2.push(b->left);
                }
                if (b->right)
                {
                    q2.push(b->right);
                }
            }
            if (!a && !b)
            {
                bool s=solve(x,y);
                if (!s)
                return 0;
                x.clear();
                y.clear();
                if (!q1.empty() && !q2.empty())
                {
                    q1.push(NULL);
                    q2.push(NULL);
                }
                else if (!q1.empty() || !q2.empty())
                {
                    return 0;
                }
                
            }
            else if (!a || !b)
            {
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends