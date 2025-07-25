/*
    Problem Link : https://leetcode.com/problems/clone-graph/
    Problem Name : Clone Graph
    Difficulty   : Medium
    Time Complexity : O(N+M)
    Space Complexity : O(N)
    ================================================================================================

    Given a reference of a node in a connected undirected graph.
    Return a deep copy (clone) of the graph.
    Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

    class Node {
        public int val;
        public List<Node> neighbors;
    }
    

    Test case format:

    For simplicity, each node's value is the same as the node's index (1-indexed). 
    For example, the first node with val == 1, the second node with val == 2, and so on. 
    The graph is represented in the test case using an adjacency list.
    An adjacency list is a collection of unordered lists used to represent a finite graph. 
    Each list describes the set of neighbors of a node in the graph.

    The given node will always be the first node with val = 1. You must return the copy of 
    the given node as a reference to the cloned graph.

    

    Example 1:


    Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
    Output: [[2,4],[1,3],[2,4],[1,3]]
    Explanation: There are 4 nodes in the graph.
    1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
    2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
    3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
    4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
    Example 2:


    Input: adjList = [[]]
    Output: [[]]
    Explanation: Note that the input contains one empty list. The graph consists of only one node 
    with val = 1 and it does not have any neighbors.
    Example 3:

    Input: adjList = []
    Output: []
    Explanation: This an empty graph, it does not have any nodes.
    

    Constraints:

    The number of nodes in the graph is in the range [0, 100].
    1 <= Node.val <= 100
    Node.val is unique for each node.
    There are no repeated edges and no self-loops in the graph.
    The Graph is connected and all nodes can be visited starting from the given node.

*/

#include<bits/stdc++.h>
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

    unordered_map<Node*, Node*> visited;

    // Function to clone a graph.
    Node* cloneGraph(Node* node) {
        // If the input node is null, return null indicating no node to clone.
        if (!node) return nullptr;

        // If the node has been already visited, return the clone from visited.
        if (visited.find(node) != visited.end()) return visited[node];

        // Create a new node with the same value as the input node.
        Node* cloneNode = new Node(node->val);
        
        // Record the visited node by mapping the original node to the clone.
        // so that it can't go throuh infinte loop
        visited[node] = cloneNode;

        // Iterate over all neighbors of the input node.
        for (auto& neighbor : node->neighbors) {
            /*  this line try to push the original node but we need deep copy node
                we will find deep copy node by creating new node, so send it to the cloneGraph function
                clonedNode->neighbors.push_back(neighbor);
            */

            // Recursively call cloneGraph for each neighbor and add it to the cloned node's neighbors.
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        // Return the cloned node.
        return cloneNode;
    }