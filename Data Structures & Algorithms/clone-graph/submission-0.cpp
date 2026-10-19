/*
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
*/

class Solution {
public:
    Node* DFS(Node* node,unordered_map<Node*,Node*> &OldToNew){
        if(OldToNew.find(node) != OldToNew.end()) return OldToNew[node];

        Node* copy = new Node(node->val);
        OldToNew[node]= copy;
        for(Node* neig : node->neighbors){
            copy->neighbors.push_back(DFS(neig,OldToNew));
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> OldToNew;
        if(node == nullptr) return nullptr;
        return DFS(node,OldToNew);
    }
};
