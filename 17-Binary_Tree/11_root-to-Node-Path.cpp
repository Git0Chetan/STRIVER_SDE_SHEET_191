// Print Root to Node Path in a Binary Tree
// Problem Statement: Print Root to Node Path In A Binary Tree. Write a program to print path from root to a given node in a binary tree.
// Problem Description: 
// We are given a binary tree T and a node V. We need to print a path from the root of the tree to the node.
// Note:
// No two nodes in the tree have the same data value.
// It is assured that the node V is present and a path always exists.


//no leetcode


#include<iostream>
using namespace std;
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}

bool Path_from_root_to_a_given_node(node *root, vector<int>& path, int n)
{
    if(root==NULL){
        return false;
    }
    
    path.push_back(root->data);
    if(root->data == n){
        return true;
    }
    
    if(Path_from_root_to_a_given_node(root->left,path,n) || Path_from_root_to_a_given_node(root->right,path,n)){
        return true;
    }
    path.pop_back();
    
    return false;
}


int main()
{
    
    node *root = newNode(4);
    root->left = newNode(5);
    root->right = newNode(7);
    root->left->right = newNode(1);
    root->left->right->left = newNode(8);
    root->left->right->right = newNode(2);
    root->right->left = newNode(9);
    root->right->right = newNode(6);
    root->right->left->right = newNode(3);

       
    int n = 9;
    cout<<"Print path from root to a given node in a binary tree : root node to node "<< n <<endl;
    vector<int> path;
    bool ans = Path_from_root_to_a_given_node(root, path, n);
       if (ans)
    {
       for (int i=0; i<path.size()-1; i++)
           cout << path[i] << "->";
       cout<<n<<endl;
    
    }
    
    else
       cout << "No Path is present from root node to node "<<n<<endl;
    return 0;
}