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
    unordered_map<Node*, Node*> m;
    Node* cloneGraph(Node* node) {
        m = {};
        return dfs(node);
    }
    Node* dfs(Node* node) {
        if (!node) return nullptr;
        if (m.contains(node)) return m[node];
        Node* tmp = new Node();
        m[node] = tmp;
        tmp->val = node->val;
        for (Node* child : node->neighbors) {
            tmp->neighbors.push_back(dfs(child));
        }
        return tmp;
    }
};
