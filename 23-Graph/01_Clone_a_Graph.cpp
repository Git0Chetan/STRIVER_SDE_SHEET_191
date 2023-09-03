// Given a reference of a node in a connected undirected graph.
// Return a deep copy (clone) of the graph.
// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

//Leetcode:133  link: https://leetcode.com/problems/clone-graph/description/

#include<iostream>
#include<unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return node;
        }

        if(mp.find(node)==mp.end()){
            mp[node]=new Node(node->val);

            for(auto adj:node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(adj));
            }
        }
        return mp[node];
    }
};
